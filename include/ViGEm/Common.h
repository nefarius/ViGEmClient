/*
MIT License

Copyright (c) 2017-2019 Nefarius Software Solutions e.U. and Contributors

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#pragma once

//
// Represents the desired target type for the emulated device.
//  
typedef enum _VIGEM_TARGET_TYPE
{
    // 
    // Microsoft Xbox 360 Controller (wired)
    // 
    Xbox360Wired = 0,
    //
    // Sony DualShock 4 (wired)
    // 
    DualShock4Wired = 2 // NOTE: 1 skipped on purpose to maintain compatibility

} VIGEM_TARGET_TYPE, *PVIGEM_TARGET_TYPE;

//
// Possible XUSB report buttons.
// 
typedef enum _XUSB_BUTTON
{
    XUSB_GAMEPAD_DPAD_UP            = 0x0001,
    XUSB_GAMEPAD_DPAD_DOWN          = 0x0002,
    XUSB_GAMEPAD_DPAD_LEFT          = 0x0004,
    XUSB_GAMEPAD_DPAD_RIGHT         = 0x0008,
    XUSB_GAMEPAD_START              = 0x0010,
    XUSB_GAMEPAD_BACK               = 0x0020,
    XUSB_GAMEPAD_LEFT_THUMB         = 0x0040,
    XUSB_GAMEPAD_RIGHT_THUMB        = 0x0080,
    XUSB_GAMEPAD_LEFT_SHOULDER      = 0x0100,
    XUSB_GAMEPAD_RIGHT_SHOULDER     = 0x0200,
    XUSB_GAMEPAD_GUIDE              = 0x0400,
    XUSB_GAMEPAD_A                  = 0x1000,
    XUSB_GAMEPAD_B                  = 0x2000,
    XUSB_GAMEPAD_X                  = 0x4000,
    XUSB_GAMEPAD_Y                  = 0x8000

} XUSB_BUTTON, *PXUSB_BUTTON;

//
// Represents an XINPUT_GAMEPAD-compatible report structure.
// 
typedef struct _XUSB_REPORT
{
    USHORT wButtons;
    BYTE bLeftTrigger;
    BYTE bRightTrigger;
    SHORT sThumbLX;
    SHORT sThumbLY;
    SHORT sThumbRX;
    SHORT sThumbRY;

} XUSB_REPORT, *PXUSB_REPORT;

//
// Initializes a _XUSB_REPORT structure.
// 
VOID FORCEINLINE XUSB_REPORT_INIT(
    _Out_ PXUSB_REPORT Report
)
{
    RtlZeroMemory(Report, sizeof(XUSB_REPORT));
}

//
// The color value (RGB) of a DualShock 4 Lightbar
// 
typedef struct _DS4_LIGHTBAR_COLOR
{
    //
    // Red part of the Lightbar (0-255).
    //
    UCHAR Red;

    //
    // Green part of the Lightbar (0-255).
    //
    UCHAR Green;

    //
    // Blue part of the Lightbar (0-255).
    //
    UCHAR Blue;

} DS4_LIGHTBAR_COLOR, *PDS4_LIGHTBAR_COLOR;

//
// DualShock 4 digital buttons
// 
typedef enum _DS4_BUTTONS
{
    DS4_BUTTON_THUMB_RIGHT      = 1 << 15,
    DS4_BUTTON_THUMB_LEFT       = 1 << 14,
    DS4_BUTTON_OPTIONS          = 1 << 13,
    DS4_BUTTON_SHARE            = 1 << 12,
    DS4_BUTTON_TRIGGER_RIGHT    = 1 << 11,
    DS4_BUTTON_TRIGGER_LEFT     = 1 << 10,
    DS4_BUTTON_SHOULDER_RIGHT   = 1 << 9,
    DS4_BUTTON_SHOULDER_LEFT    = 1 << 8,
    DS4_BUTTON_TRIANGLE         = 1 << 7,
    DS4_BUTTON_CIRCLE           = 1 << 6,
    DS4_BUTTON_CROSS            = 1 << 5,
    DS4_BUTTON_SQUARE           = 1 << 4

} DS4_BUTTONS, *PDS4_BUTTONS;

//
// DualShock 4 special buttons
// 
typedef enum _DS4_SPECIAL_BUTTONS
{
    DS4_SPECIAL_BUTTON_PS           = 1 << 0,
    DS4_SPECIAL_BUTTON_TOUCHPAD     = 1 << 1

} DS4_SPECIAL_BUTTONS, *PDS4_SPECIAL_BUTTONS;

//
// DualShock 4 directional pad (HAT) values
// 
typedef enum _DS4_DPAD_DIRECTIONS
{
    DS4_BUTTON_DPAD_NONE        = 0x8,
    DS4_BUTTON_DPAD_NORTHWEST   = 0x7,
    DS4_BUTTON_DPAD_WEST        = 0x6,
    DS4_BUTTON_DPAD_SOUTHWEST   = 0x5,
    DS4_BUTTON_DPAD_SOUTH       = 0x4,
    DS4_BUTTON_DPAD_SOUTHEAST   = 0x3,
    DS4_BUTTON_DPAD_EAST        = 0x2,
    DS4_BUTTON_DPAD_NORTHEAST   = 0x1,
    DS4_BUTTON_DPAD_NORTH       = 0x0

} DS4_DPAD_DIRECTIONS, *PDS4_DPAD_DIRECTIONS;

typedef enum _DS4_BITMASK_FLAGS
{
    DS4_BATTERY_CHARGED = 1 << 3,
    DS4_USB_CABLE_CONNECTED = 1 << 4,
    DS4_HEADPHONE_CONNECTED = 1 << 5,
    DS4_HEADPHONE_JACK_MIC_CONNECTED = 1 << 6,
    DS4_HEADPHONE_W_MIC_CONNECTED = (DS4_HEADPHONE_CONNECTED | DS4_HEADPHONE_JACK_MIC_CONNECTED)

}DS4_BITMASK_FLAGS, *PDS4_BITMASK_FLAGS;

#include <pshpack1.h>

//
// DualShock 4 HID Input report
// 
typedef struct _DS4_REPORT
{
    BYTE bThumbLX;
    BYTE bThumbLY;
    BYTE bThumbRX;
    BYTE bThumbRY;
    USHORT wButtons;
    BYTE bSpecial;
    BYTE bTriggerL;
    BYTE bTriggerR;

} DS4_REPORT, *PDS4_REPORT;

//
// DualShock 4 HID Input Touchpad data
//
typedef struct _DS4_TOUCH_DATA
{
    BYTE bIsUp_TrackingID;
    BYTE abCoords[3];

}DS4_TOUCH_DATA,*PDS4_TOUCH_DATA;

//
// Dualshock 4 HID Input Report Extension
//
typedef struct _DS4_REPORT_EX
{
    USHORT wTimeStamp;
    BYTE bBatteryLvl;
    SHORT nGyroX;
    SHORT nGyroY;
    SHORT nGyroZ;
    SHORT nAccX;
    SHORT nAccY;
    SHORT nAccZ;
    BYTE abReserved0[5];
    BYTE bBitmask;
    BYTE abReserved1[2];
    BYTE bTPADMask;
    BYTE bTPADIncrement;
    /*
    TODO: Check V1 touch data, V2 over USB has been observed so far to only send max touch data of 2 fingers
    and it doesn't track previous, but holds it persistently until another update. Along with conflicting data on what
    bTPADMask means.
    */
    DS4_TOUCH_DATA aCurrentTouchData[2];
    DS4_TOUCH_DATA aPreviousTouchData[2];

    BYTE abReserved3[13]; //TODO: Quadruple check as it feels off

} DS4_REPORT_EX,*PDS4_REPORT_EX;

#include <poppack.h>

//
// Sets the current state of the D-PAD on a DualShock 4 report.
// 
VOID FORCEINLINE DS4_SET_DPAD(
    _Out_ PDS4_REPORT Report,
    _In_ DS4_DPAD_DIRECTIONS Dpad
)
{
    Report->wButtons &= ~0xF;
    Report->wButtons |= (USHORT)Dpad;
}

//
// Sets the current state of the TPAD on a Dualshock 4 report.
//
VOID FORCEINLINE DS4_SET_TPAD(
    _Out_ PDS4_REPORT_EX ReportEx,
    _In_ BOOLEAN FirstFinger,
    _In_ USHORT X,
    _In_ USHORT Y,
    _In_ BYTE TouchId,
    _In_ BOOLEAN Active)
{
    //TODO: Check bounds since there is a spare bit
    if (FirstFinger) {
        ReportEx->aCurrentTouchData[0].bIsUp_TrackingID = (!Active << 7) + TouchId;
        ReportEx->aCurrentTouchData[0].abCoords[0] = (BYTE)(X & 0xFF);
        ReportEx->aCurrentTouchData[0].abCoords[1] = (BYTE)(((X & 0xF00) >> 8) | ((Y & 0xF) << 4));
        ReportEx->aCurrentTouchData[0].abCoords[2] = (BYTE)((Y & 0xFF0) >> 4);
    }
    else {
        ReportEx->aCurrentTouchData[1].bIsUp_TrackingID = (!Active << 7) + TouchId;
        ReportEx->aCurrentTouchData[1].abCoords[0] = (BYTE)(X & 0xFF);
        ReportEx->aCurrentTouchData[1].abCoords[1] = (BYTE)(((X & 0xF00) >> 8) | ((Y & 0xF) << 4));
        ReportEx->aCurrentTouchData[1].abCoords[2] = (BYTE)((Y & 0xFF0) >> 4);
    }
}

VOID FORCEINLINE DS4_REPORT_INIT(
    _Out_ PDS4_REPORT Report
)
{
    RtlZeroMemory(Report, sizeof(DS4_REPORT));

    Report->bThumbLX = 0x80;
    Report->bThumbLY = 0x80;
    Report->bThumbRX = 0x80;
    Report->bThumbRY = 0x80;

    DS4_SET_DPAD(Report, DS4_BUTTON_DPAD_NONE);
}

VOID FORCEINLINE DS4_REPORT_EX_INIT(
    _Out_ PDS4_REPORT_EX ReportEx
)
{
    RtlZeroMemory(ReportEx, sizeof(DS4_REPORT_EX));

    //TODO: Update once more testing is done
    ReportEx->aCurrentTouchData[0].bIsUp_TrackingID = (1 << 7);
    ReportEx->aCurrentTouchData[1].bIsUp_TrackingID = (1 << 7);
    ReportEx->aPreviousTouchData[0].bIsUp_TrackingID = (1 << 7);
    ReportEx->aPreviousTouchData[1].bIsUp_TrackingID = (1 << 7);
}

