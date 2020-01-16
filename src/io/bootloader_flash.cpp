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

bool isBootloader(const char * filename)
{
  FIL file;
  f_open(&file, filename, FA_READ);
  uint8_t buffer[1024];
  UINT count;

  if (f_read(&file, buffer, sizeof(buffer), &count) != FR_OK || count != sizeof(buffer)) {
    return false;
  }

  return isBootloaderStart(buffer);
}

void bootloaderFlash(const char * filename)
{
  FIL file;
  uint8_t buffer[1024];
  UINT count;

  pausePulses();

  f_open(&file, filename, FA_READ);

  static uint8_t unlocked = 0;
  if (!unlocked) {
    unlocked = 1;
    unlockFlash();
  }

  for (int i = 0; i < BOOTLOADER_SIZE; i += 1024) {
    watchdogSuspend(1000/*10s*/);
    if (f_read(&file, buffer, sizeof(buffer), &count) != FR_OK || count != sizeof(buffer)) {
      POPUP_WARNING(STR_SDCARD_ERROR);
      break;
    }
    if (i == 0 && !isBootloaderStart(buffer)) {
      POPUP_WARNING(STR_INCOMPATIBLE);
      break;
    }
    for (int j = 0; j < 1024; j += FLASH_PAGESIZE) {
      flashWrite(CONVERT_UINT_PTR(FIRMWARE_ADDRESS + i + j), CONVERT_UINT_PTR(buffer + j));
    }
#if !defined(COLORLCD)
    drawProgressScreen("Bootloader", STR_WRITING, i, BOOTLOADER_SIZE);
#endif
#if defined(SIMU)
    // add an artificial delay and check for simu quit
    if (SIMU_SLEEP_OR_EXIT_MS(30))
      break;
#endif
  }

  watchdogSuspend(0);
  WDG_RESET();

  if (unlocked) {
    lockFlash();
    unlocked = 0;
  }

  f_close(&file);

  resumePulses();
}