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
#include "debug.h"
#include "usb_driver.h"
#include "class/hid/device/gpd/udi_hid_gpd.h"

#ifndef SIMU

extern "C" {
#include "udc/udc.h"
}

static bool usbDriverStarted = false;
#if defined(BOOT)
static usbMode selectedUsbMode = USB_MASS_STORAGE_MODE;
#else
static usbMode selectedUsbMode = USB_UNSELECTED_MODE;
#endif

int getSelectedUsbMode()
{
    return selectedUsbMode;
}

void setSelectedUsbMode(int mode)
{
    selectedUsbMode = usbMode(mode);
}

int usbPlugged()
{
    return (PIOC->PIO_PDSR & PIO_PC25);
}

void usbInit()
{
    usbDriverStarted = false;
}

bool usbStarted()
{
    return usbDriverStarted;
}

void usbPluggedIn()
{
    
}

void startJoystick()
{
    udc_start();
    udc_remotewakeup();
}

void startCDCSerial()
{

}

void startMassStorage()
{
    static bool initialized = false;

    if (sd_card_ready()) {
        TRACE_DEBUG("usbMassStorage\n\r");

        if (sdMounted()) {
            Card_state = SD_ST_DATA;
            audioQueue.stopSD();
            logsClose();
            f_mount(nullptr, "", 0); // unmount SD
        }

        if (!initialized) {
            /* Initialize LUN */
            //MEDSdcard_Initialize(&(medias[DRV_SDMMC]), 0);

            //LUN_Init(&(luns[DRV_SDMMC]), &(medias[DRV_SDMMC]),
            //    msdBuffer, MSD_BUFFER_SIZE,
            //    0, 0, 0, 0,
            //    MSDCallbacks_Data);

            /* BOT driver initialization */
            //MSDDriver_Initialize(luns, 1);

            // VBus_Configure();
            //USBD_Connect();

            initialized = true;
        }

        /* Mass storage state machine */
        //for (uint8_t i=0; i<50; i++)
        //  MSDDriver_StateMachine();
    }
    else {
        //msdReadTotal = 0;
        //msdWriteTotal = 0;
    }
}

void usbStart()
{
    switch (getSelectedUsbMode()) {
#if !defined(BOOT)
    case USB_JOYSTICK_MODE:
        startJoystick();
        break;
#endif
#if defined(USB_SERIAL)
    case USB_SERIAL_MODE:
        startCDCSerial();
        break;
#endif
    default:
    case USB_MASS_STORAGE_MODE:
        startMassStorage();
        break;
    }
    usbDriverStarted = true;
}

void usbStop()
{
    udc_stop();

    usbDriverStarted = false;
}

void usbJoystickUpdate()
{
    static uint8_t HID_Buffer[9];

    HID_Buffer[0] = 0; // buttons
    for (int i = 0; i < 8; ++i) {
        if ( channelOutputs[i+8] > 0 ) {
            HID_Buffer[0] |= (1 << i);
        }
    }

    //analog values
    for (int i = 0; i < 8; ++i) {
        int16_t value = channelOutputs[i] / 8;
        if ( value > 127 ) value = 127;
        else if ( value < -127 ) value = -127;
        HID_Buffer[i+1] = static_cast<int8_t>(value);
    }

    udi_hid_gpd_update(HID_Buffer);
}

void usbSerialPutc(uint8_t c)
{
    
}


#endif