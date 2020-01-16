/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "opentx.h"

#if defined(LIBOPENUI)
  #include "mainwindow.h"
#endif

uint8_t currentSpeakerVolume = 255;
uint8_t requiredSpeakerVolume = 255;
uint8_t mainRequestFlags = 0;

#if defined(LIBOPENUI)
void openUsbMenu()
{
  static Menu * menu = nullptr;
  if (menu)
    return;
  menu = new Menu(&mainWindow);
  menu->setCloseHandler([]() {
    menu = nullptr;
  });
  menu->setTitle("USB");
  menu->addLine(STR_USB_JOYSTICK, [] {
    setSelectedUsbMode(USB_JOYSTICK_MODE);
  });
  menu->addLine(STR_USB_MASS_STORAGE, [] {
    setSelectedUsbMode(USB_MASS_STORAGE_MODE);
  });
#if defined(DEBUG)
  menu->addLine(STR_USB_SERIAL, [] {
    setSelectedUsbMode(USB_SERIAL_MODE);
  });
#endif
}
#elif defined(STM32)
void onUSBConnectMenu(const char *result)
{
  if (result == STR_USB_MASS_STORAGE) {
    setSelectedUsbMode(USB_MASS_STORAGE_MODE);
  }
  else if (result == STR_USB_JOYSTICK) {
    setSelectedUsbMode(USB_JOYSTICK_MODE);
  }
  else if (result == STR_USB_SERIAL) {
    setSelectedUsbMode(USB_SERIAL_MODE);
  }
}

void openUsbMenu()
{
  POPUP_MENU_ADD_ITEM(STR_USB_JOYSTICK);
  POPUP_MENU_ADD_ITEM(STR_USB_MASS_STORAGE);
#if defined(DEBUG)
  POPUP_MENU_ADD_ITEM(STR_USB_SERIAL);
#endif
  POPUP_MENU_START(onUSBConnectMenu);
}
#endif

void handleUsbConnection()
{
#if defined(STM32) && !defined(SIMU)
  if (!usbStarted() && usbPlugged()) {
    if (getSelectedUsbMode() == USB_UNSELECTED_MODE) {
      if (g_eeGeneral.USBMode == USB_UNSELECTED_MODE && popupMenuItemsCount == 0) {
        openUsbMenu();
      }
      else {
        setSelectedUsbMode(g_eeGeneral.USBMode);
      }
    }
    else {
      if (getSelectedUsbMode() == USB_MASS_STORAGE_MODE) {
        opentxClose(false);
        usbPluggedIn();
      }
      usbStart();
    }
  }

  if (usbStarted() && !usbPlugged()) {
    usbStop();
    if (getSelectedUsbMode() == USB_MASS_STORAGE_MODE) {
      opentxResume();
      putEvent(EVT_ENTRY);
    }
    setSelectedUsbMode(USB_UNSELECTED_MODE);
  }
#endif // defined(STM32) && !defined(SIMU)
}

#if defined(JACK_DETECT_GPIO) && !defined(SIMU)
bool isJackPlugged()
{
  // debounce
  static bool debounced_state = 0;
  static bool last_state = 0;

  if (GPIO_ReadInputDataBit(JACK_DETECT_GPIO, JACK_DETECT_GPIO_PIN)) {
    if (!last_state) {
      debounced_state = false;
    }
    last_state = false;
  }
  else {
    if (last_state) {
      debounced_state = true;
    }
    last_state = true;
  }
  return debounced_state;
}
#endif

#if defined(PCBXLITES)
uint8_t jackState = SPEAKER_ACTIVE;

const char STR_JACK_HEADPHONE[] = "Headphone";
const char STR_JACK_TRAINER[] = "Trainer";

void onJackConnectMenu(const char * result)
{
  if (result == STR_JACK_HEADPHONE) {
    jackState = HEADPHONE_ACTIVE;
    disableSpeaker();
    enableHeadphone();
  }
  else if (result == STR_JACK_TRAINER) {
    jackState = TRAINER_ACTIVE;
    enableTrainer();
  }
}

void handleJackConnection()
{
  if (jackState == SPEAKER_ACTIVE && isJackPlugged()) {
    if (g_eeGeneral.jackMode == JACK_HEADPHONE_MODE) {
      jackState = HEADPHONE_ACTIVE;
      disableSpeaker();
      enableHeadphone();
    }
    else if (g_eeGeneral.jackMode == JACK_TRAINER_MODE) {
      jackState = TRAINER_ACTIVE;
      enableTrainer();
    }
    else if (popupMenuItemsCount == 0) {
      POPUP_MENU_ADD_ITEM(STR_JACK_HEADPHONE);
      POPUP_MENU_ADD_ITEM(STR_JACK_TRAINER);
      POPUP_MENU_START(onJackConnectMenu);
    }
  }
  else if (jackState == SPEAKER_ACTIVE && !isJackPlugged() && popupMenuItemsCount > 0 && popupMenuHandler == onJackConnectMenu) {
    popupMenuItemsCount = 0;
  }
  else if (jackState != SPEAKER_ACTIVE && !isJackPlugged()) {
    jackState = SPEAKER_ACTIVE;
    enableSpeaker();
  }
}
#endif

void checkSpeakerVolume()
{
  if (currentSpeakerVolume != requiredSpeakerVolume) {
    currentSpeakerVolume = requiredSpeakerVolume;
#if !defined(SOFTWARE_VOLUME)
    setScaledVolume(currentSpeakerVolume);
#endif
  }
}

#if defined(EEPROM)
void checkEeprom()
{
  if (eepromIsWriting())
    eepromWriteProcess();
  else if (TIME_TO_WRITE())
    storageCheck(false);
}
#else
void checkEeprom()
{
#if defined(RTC_BACKUP_RAM) && !defined(SIMU)
  if (TIME_TO_BACKUP_RAM()) {
    rambackupWrite();
    rambackupDirtyMsk = 0;
  }
#endif
  if (TIME_TO_WRITE()) {
    storageCheck(false);
  }
}
#endif

#define BAT_AVG_SAMPLES       8

void checkBatteryAlarms()
{
  // TRACE("checkBatteryAlarms()");
  if (IS_TXBATT_WARNING()) {
    AUDIO_TX_BATTERY_LOW();
    // TRACE("checkBatteryAlarms(): battery low");
  }
#if defined(PCBSKY9X)
  else if (g_eeGeneral.mAhWarn && (g_eeGeneral.mAhUsed + Current_used * (488 + g_eeGeneral.txCurrentCalibration)/8192/36) / 500 >= g_eeGeneral.mAhWarn) { // TODO move calculation into board file
    AUDIO_TX_MAH_HIGH();
  }
#endif
}

void checkBattery()
{
  static uint32_t batSum;
  static uint8_t sampleCount;
  // filter battery voltage by averaging it
  if (g_vbat100mV == 0) {
    g_vbat100mV = (getBatteryVoltage() + 5) / 10;
    batSum = 0;
    sampleCount = 0;
  }
  else {
    batSum += getBatteryVoltage();
    // TRACE("checkBattery(): sampled = %d", getBatteryVoltage());
    if (++sampleCount >= BAT_AVG_SAMPLES) {
      g_vbat100mV = (batSum + BAT_AVG_SAMPLES * 5 ) / (BAT_AVG_SAMPLES * 10);
      batSum = 0;
      sampleCount = 0;
      // TRACE("checkBattery(): g_vbat100mV = %d", g_vbat100mV);
    }
  }
}

void periodicTick_1s()
{
  checkBattery();
}

void periodicTick_10s()
{
  checkBatteryAlarms();
#if defined(LUA)
  checkLuaMemoryUsage();
#endif
}

void periodicTick()
{
  static uint8_t count10s;
  static uint32_t lastTime;
  if ( (get_tmr10ms() - lastTime) >= 100 ) {
    lastTime += 100;
    periodicTick_1s();
    if (++count10s >= 10) {
      count10s = 0;
      periodicTick_10s();
    }
  }
}

#if defined(GUI) && defined(COLORLCD)
void guiMain(event_t evt)
{
  bool refreshNeeded = false;

#if defined(LUA) && !defined(LIBOPENUI)
  uint32_t t0 = get_tmr10ms();
  static uint32_t lastLuaTime = 0;
  uint16_t interval = (lastLuaTime == 0 ? 0 : (t0 - lastLuaTime));
  lastLuaTime = t0;
  if (interval > maxLuaInterval) {
    maxLuaInterval = interval;
  }

  // run Lua scripts that don't use LCD (to use CPU time while LCD DMA is running)
  DEBUG_TIMER_START(debugTimerLuaBg);
  luaTask(0, RUN_MIX_SCRIPT | RUN_FUNC_SCRIPT | RUN_TELEM_BG_SCRIPT, false);
  DEBUG_TIMER_STOP(debugTimerLuaBg);
  // wait for LCD DMA to finish before continuing, because code from this point
  // is allowed to change the contents of LCD buffer
  //
  // WARNING: make sure no code above this line does any change to the LCD display buffer!
  //
  DEBUG_TIMER_START(debugTimerLcdRefreshWait);
  lcdRefreshWait();
  DEBUG_TIMER_STOP(debugTimerLcdRefreshWait);

  // draw LCD from menus or from Lua script
  // run Lua scripts that use LCD

  DEBUG_TIMER_START(debugTimerLuaFg);
  refreshNeeded = luaTask(evt, RUN_STNDAL_SCRIPT, true);
  if (!refreshNeeded) {
    refreshNeeded = luaTask(evt, RUN_TELEM_FG_SCRIPT, true);
  }
  DEBUG_TIMER_STOP(debugTimerLuaFg);

  t0 = get_tmr10ms() - t0;
  if (t0 > maxLuaDuration) {
    maxLuaDuration = t0;
  }
#elif !defined(LIBOPENUI)
  lcdRefreshWait();   // WARNING: make sure no code above this line does any change to the LCD display buffer!
#endif

  bool screenshotRequested = (mainRequestFlags & (1u << REQUEST_SCREENSHOT));

#if defined(LIBOPENUI)
  mainWindow.run();
#else
  if (!refreshNeeded) {
    DEBUG_TIMER_START(debugTimerMenus);
    while (true) {
      // normal GUI from menus
      const char * warn = warningText;
      uint8_t menu = popupMenuItemsCount;
      static bool popupDisplayed = false;
      if (warn || menu) {
        if (popupDisplayed == false) {
          menuHandlers[menuLevel](EVT_REFRESH);
          lcdDrawBlackOverlay();
          TIME_MEASURE_START(storebackup);
          lcdStoreBackupBuffer();
          TIME_MEASURE_STOP(storebackup);
        }
        if (popupDisplayed == false || evt || screenshotRequested) {
          popupDisplayed = lcdRestoreBackupBuffer();
          if (warn) {
            DISPLAY_WARNING(evt);
          }
          if (menu) {
            const char * result = runPopupMenu(evt);
            if (result) {
              TRACE("popupMenuHandler(%s)", result);
              auto handler = popupMenuHandler;
              if (result != STR_UPDATE_LIST)
                CLEAR_POPUP();
              handler(result);
              if (menuEvent == 0) {
                evt = EVT_REFRESH;
                continue;
              }
            }
          }
          refreshNeeded = true;
        }
      }
      else {
        if (popupDisplayed) {
          if (evt == 0) {
            evt = EVT_REFRESH;
          }
          popupDisplayed = false;
        }
        DEBUG_TIMER_START(debugTimerMenuHandlers);
        refreshNeeded = menuHandlers[menuLevel](evt);
        DEBUG_TIMER_STOP(debugTimerMenuHandlers);
      }

      if (menuEvent == EVT_ENTRY) {
        menuVerticalPosition = 0;
        menuHorizontalPosition = 0;
        evt = menuEvent;
        menuEvent = 0;
      }
      else if (menuEvent == EVT_ENTRY_UP) {
        menuVerticalPosition = menuVerticalPositions[menuLevel];
        menuHorizontalPosition = 0;
        evt = menuEvent;
        menuEvent = 0;
      }
      else {
        break;
      }
    }
    DEBUG_TIMER_STOP(debugTimerMenus);
  }

  if (screenshotRequested) {
    writeScreenshot();
    mainRequestFlags &= ~(1u << REQUEST_SCREENSHOT);
  }

  if (refreshNeeded) {
    DEBUG_TIMER_START(debugTimerLcdRefresh);
    lcdRefresh();
    DEBUG_TIMER_STOP(debugTimerLcdRefresh);
  }
#endif
}
#elif defined(GUI)
void handleGui(event_t event) {
  // if Lua standalone, run it and don't clear the screen (Lua will do it)
  // else if Lua telemetry view, run it and don't clear the screen
  // else clear scren and show normal menus
#if defined(LUA)
  if (luaTask(event, RUN_STNDAL_SCRIPT, true)) {
    // standalone script is active
  }
  else if (luaTask(event, RUN_TELEM_FG_SCRIPT, true)) {
    // the telemetry screen is active
    menuHandlers[menuLevel](event);
  }
  else
#endif
  {
    lcdClear();
    menuHandlers[menuLevel](event);
    drawStatusLine();
  }
}

void guiMain(event_t evt)
{
#if defined(LUA)
  // TODO better lua stopwatch
  uint32_t t0 = get_tmr10ms();
  static uint32_t lastLuaTime = 0;
  uint16_t interval = (lastLuaTime == 0 ? 0 : (t0 - lastLuaTime));
  lastLuaTime = t0;
  if (interval > maxLuaInterval) {
    maxLuaInterval = interval;
  }

  // run Lua scripts that don't use LCD (to use CPU time while LCD DMA is running)
  luaTask(0, RUN_MIX_SCRIPT | RUN_FUNC_SCRIPT | RUN_TELEM_BG_SCRIPT, false);

  t0 = get_tmr10ms() - t0;
  if (t0 > maxLuaDuration) {
    maxLuaDuration = t0;
  }
#endif //#if defined(LUA)

  // wait for LCD DMA to finish before continuing, because code from this point
  // is allowed to change the contents of LCD buffer
  //
  // WARNING: make sure no code above this line does any change to the LCD display buffer!
  //
  lcdRefreshWait();

  if (menuEvent) {
    // we have a popupMenuActive entry or exit event
    menuVerticalPosition = (menuEvent == EVT_ENTRY_UP) ? menuVerticalPositions[menuLevel] : 0;
    menuHorizontalPosition = 0;
    evt = menuEvent;
    menuEvent = 0;
  }

  if (isEventCaughtByPopup()) {
    handleGui(0);
  }
  else {
    handleGui(evt);
    evt = 0;
  }

  if (warningText) {
    // show warning on top of the normal menus
    DISPLAY_WARNING(evt);
  }
  else if (popupMenuItemsCount > 0) {
    // show popup menu on top of the normal menus
    const char * result = runPopupMenu(evt);
    if (result) {
      TRACE("popupMenuHandler(%s)", result);
      auto handler = popupMenuHandler;
      if (result != STR_UPDATE_LIST)
        CLEAR_POPUP();
      handler(result);
    }
  }

  lcdRefresh();

  if (mainRequestFlags & (1u << REQUEST_SCREENSHOT)) {
    writeScreenshot();
    mainRequestFlags &= ~(1u << REQUEST_SCREENSHOT);
  }
}
#endif

void perMain()
{
  DEBUG_TIMER_START(debugTimerPerMain1);

#if defined(PCBSKY9X)
  calcConsumption();
#endif

  checkSpeakerVolume();

  if (!usbPlugged()) {
    checkEeprom();
    logsWrite();
  }

  handleUsbConnection();

#if defined(PCBXLITES)
  handleJackConnection();
#endif

  checkTrainerSettings();
  periodicTick();
  DEBUG_TIMER_STOP(debugTimerPerMain1);

  if (mainRequestFlags & (1 << REQUEST_FLIGHT_RESET)) {
    TRACE("Executing requested Flight Reset");
    flightReset();
    mainRequestFlags &= ~(1 << REQUEST_FLIGHT_RESET);
  }

  checkBacklight();

#if !defined(LIBOPENUI)
  event_t evt = getEvent(false);
#endif

#if defined(RTC_BACKUP_RAM)
  if (globalData.unexpectedShutdown) {
    drawFatalErrorScreen(STR_EMERGENCY_MODE);
    return;
  }
#endif

#if defined(STM32)
  if (!usbPlugged() && SD_CARD_PRESENT() && !sdMounted()) {
    sdMount();
  }
#endif

#if !defined(EEPROM)
  // In case the SD card is removed during the session
  if (!usbPlugged() && !SD_CARD_PRESENT() && !globalData.unexpectedShutdown) {
    drawFatalErrorScreen(STR_NO_SDCARD);
    return;
  }
#endif

#if defined(STM32)
  if (usbPlugged() && getSelectedUsbMode() == USB_MASS_STORAGE_MODE) {
#if defined(LIBOPENUI)
    #warning "TODO USB plugged view"
#else
    // disable access to menus
    lcdClear();
    menuMainView(0);
    lcdRefresh();
#endif
    return;
  }
#endif

#if defined(GUI)
  DEBUG_TIMER_START(debugTimerGuiMain);
#if defined(LIBOPENUI)
  guiMain(0);
#else
  guiMain(evt);
#endif
  DEBUG_TIMER_STOP(debugTimerGuiMain);
#endif

#if defined(PCBX9E) && !defined(SIMU)
  toplcdRefreshStart();
  setTopFirstTimer(getValue(MIXSRC_FIRST_TIMER+g_model.toplcdTimer));
  setTopSecondTimer(g_eeGeneral.globalTimer + sessionTimer);
  setTopRssi(TELEMETRY_RSSI());
  setTopBatteryValue(g_vbat100mV);
  setTopBatteryState(GET_TXBATT_BARS(10), IS_TXBATT_WARNING());
  toplcdRefreshEnd();
#endif

#if defined(INTERNAL_GPS)
  gpsWakeup();
#endif
}