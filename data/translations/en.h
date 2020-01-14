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
 *
 */



/*
 * !!!!! DO NOT EDIT en.h - EDIT en.h.txt INSTEAD !!!!!!!
 *
 * In order to make translations easier en.h.txt is parsed and national
 * characters are replaced by bitmap codes. The result is en.h.
 * See translate.py in the util folder for the list of character codes
 *
 * !!!!! DO NOT EDIT en.h - EDIT en.h.txt INSTEAD !!!!!!!
 */

/*
 * Formatting octal codes available in TR_ strings:
 *  \037\x           -sets LCD x-coord (x value in octal)
 *  \036             -newline
 *  \035             -horizontal tab (ARM only)
 *  \001 to \034     -extended spacing (value * FW/2)
 *  \0               -ends current string
 */



// NON ZERO TERMINATED STRINGS
#define LEN_OFFON                      "\003"
#define TR_OFFON                       "OFF""ON\0"

#define LEN_MMMINV                     "\003"
#define TR_MMMINV                      "---""INV"

#define LEN_VBEEPMODE                  "\005"
#define TR_VBEEPMODE                   "Quiet""Alarm""NoKey""All\0 "

#define LEN_VBLMODE                    TR("\004", "\010")
#define TR_VBLMODE                     TR("OFF\0""Keys""Ctrl""Both""ON\0 ", "OFF\0    ""Keys\0   ""Controls""Both\0   ""ON\0     ")

#define LEN_TRNMODE                    "\003"
#define TR_TRNMODE                     "OFF""+=\0"":=\0"

#define LEN_TRNCHN                     "\003"
#define TR_TRNCHN                      "CH1CH2CH3CH4"

#define LEN_AUX_SERIAL_MODES           "\015"
#if defined(CLI) || defined(DEBUG)
#define TR_AUX_SERIAL_MODES            "Debug\0       ""Telem Mirror\0""Telemetry In\0""SBUS Trainer\0""LUA\0         "
#else
#define TR_AUX_SERIAL_MODES            "OFF\0         ""Telem Mirror\0""Telemetry In\0""SBUS Trainer\0""LUA\0         "
#endif

#define LEN_SWTYPES                    "\006"
#define TR_SWTYPES                     "None\0 ""Toggle""2POS\0 ""3POS\0"

#define LEN_POTTYPES                    TR("\013", "\017")
#define TR_POTTYPES                     TR("None\0      ""Pot w. det\0""Multipos\0  ""Pot\0       ",  "None\0          ""Pot with detent""Multipos Switch""Pot\0")

#define LEN_SLIDERTYPES                "\006"
#define TR_SLIDERTYPES                 "None\0 ""Slider"

#define LEN_VLCD                       "\006"
#define TR_VLCD                        "NormalOptrex"

#define LEN_VPERSISTENT                "\014"
#define TR_VPERSISTENT                 "OFF\0        ""Flight\0     ""Manual Reset"

#define LEN_COUNTRYCODES               TR("\002", "\007")
#define TR_COUNTRYCODES                TR("US""JP""EU", "America""Japan\0 ""Europe\0")

#define LEN_USBMODES                   TR("\006", "\010")
#define TR_USBMODES                    TR("Ask\0  ""Joyst\0""SDCard""Serial", "Ask\0    ""Joystick""Storage\0""Serial\0 ")

#define LEN_JACKMODES                  "\007"
#define TR_JACKMODES                   "Ask\0   ""Audio\0 ""Trainer"

#define LEN_TELEMETRY_PROTOCOLS        "\017"
#define TR_TELEMETRY_PROTOCOLS         "FrSky S.PORT\0  ""FrSky D\0       ""FrSky D (cable)""TBS Crossfire\0 ""Spektrum\0      ""AFHDS2A IBUS\0  ""Multi Telemetry"

#define TR_MULTI_CUSTOM                "Custom"

#define LEN_VTRIMINC                   TR("\006", "\013")
#define TR_VTRIMINC                    TR("Expo\0 ""ExFine""Fine\0 ""Medium""Coarse", "Exponential""Extra Fine\0""Fine\0      ""Medium\0    ""Coarse\0    ")

#define LEN_VDISPLAYTRIMS              "\006"
#define TR_VDISPLAYTRIMS               "No\0   ""Change""Yes\0"

#define LEN_VBEEPCOUNTDOWN             "\006"
#define TR_VBEEPCOUNTDOWN              "SilentBeeps\0Voice\0Haptic"

#define LEN_VVARIOCENTER               "\006"
#define TR_VVARIOCENTER                "Tone\0 ""Silent"

#define LEN_CURVE_TYPES                "\010"
#define TR_CURVE_TYPES                 "Standard""Custom\0"

#define LEN_RETA123                    "\001"

#if defined(PCBHORUS)
  #define TR_RETA123                   "RETA13245LR"
#elif defined(PCBX9E)
  #define TR_RETA123                   "RETA1234LRLR"
#elif defined(PCBTARANIS) || defined(REVX)
  #define TR_RETA123                   "RETA123LR"
#elif defined(PCBSKY9X)
  #define TR_RETA123                   "RETA123a"
#else
  #define TR_RETA123                   "RETA123"
#endif

#if defined(PCBSKY9X) && defined(REVX)
  #define LEN_VOUTPUT_TYPE             "\011"
  #define TR_VOUTPUT_TYPE              "OpenDrain""PushPull\0"
#endif

#define LEN_VCURVEFUNC                 "\003"
#define TR_VCURVEFUNC                  "---""x>0""x<0""|x|""f>0""f<0""|f|"

#define LEN_VMLTPX                     "\010"
#define TR_VMLTPX                      "Add\0    ""Multiply""Replace\0"

#define LEN_VMLTPX2                    "\002"
#define TR_VMLTPX2                     "+=""*="":="

#define LEN_VMIXTRIMS                  "\003"

#if defined(PCBHORUS)
  #define TR_VMIXTRIMS                 "OFF""ON\0""Rud""Ele""Thr""Ail""T5\0""T6\0"
#else
  #define TR_VMIXTRIMS                 "OFF""ON\0""Rud""Ele""Thr""Ail"
#endif

#if LCD_W >= 212
  #define TR_CSWTIMER                  "Timer"
  #define TR_CSWSTICKY                 "Stcky"
  #define TR_CSWRANGE                  "Range"
  #define TR_CSWSTAY                   "Edge\0"
#else
  #define TR_CSWTIMER                  "Tim\0 "
  #define TR_CSWSTICKY                 "Stky\0"
    #define TR_CSWRANGE                "Rnge\0"
    #define TR_CSWSTAY                 "Edge\0"
#endif

  #define TR_CSWEQUAL                  "a=x\0 "

#define LEN_VCSWFUNC                   "\005"
#define TR_VCSWFUNC                    "---\0 " TR_CSWEQUAL "a\173x\0 ""a>x\0 ""a<x\0 " TR_CSWRANGE "|a|>x""|a|<x""AND\0 ""OR\0  ""XOR\0 " TR_CSWSTAY "a=b\0 ""a>b\0 ""a<b\0 ""\306}x\0 ""|\306|}x" TR_CSWTIMER TR_CSWSTICKY

#define LEN_VFSWFUNC                   "\012"

#if defined(VARIO)
  #define TR_VVARIO                    "Vario\0    "
#else
  #define TR_VVARIO                    "[Vario]\0  "
#endif

#if defined(AUDIO)
  #define TR_SOUND                     "Play Sound"
#else
  #define TR_SOUND                     "Beep\0     "
#endif

#if defined(HAPTIC)
  #define TR_HAPTIC                    "Haptic\0   "
#else
  #define TR_HAPTIC                    "[Haptic]\0 "
#endif

#if defined(VOICE)
  #if defined(PCBSKY9X)
    #define TR_PLAY_TRACK              "Play\0     "
  #else
    #define TR_PLAY_TRACK              "Play Track"
  #endif
  #define TR_PLAY_BOTH                 "Play Both\0"
  #define TR_PLAY_VALUE                TR("Play Val\0 ", "Play Value")
#else
  #define TR_PLAY_TRACK                "[Play Trk]"
  #define TR_PLAY_BOTH                 "[Play Bth]"
  #define TR_PLAY_VALUE                "[Play Val]"
#endif

#define TR_SF_BG_MUSIC                 "BgMusic\0  ""BgMusic ||"

#if defined(SDCARD)
  #define TR_SDCLOGS                   "SD Logs\0  "
#else
  #define TR_SDCLOGS                   "[SD Logs]\0"
#endif

#if defined(GVARS)
  #define TR_ADJUST_GVAR               "Adjust\0   "
#else
  #define TR_ADJUST_GVAR               "[AdjustGV]"
#endif

#if defined(LUA)
  #define TR_SF_PLAY_SCRIPT            "Lua Script"
#else
  #define TR_SF_PLAY_SCRIPT            "[Lua]\0    "
#endif

#if defined(DEBUG)
  #define TR_SF_TEST                   "Test\0"
#else
  #define TR_SF_TEST
#endif

#if defined(OVERRIDE_CHANNEL_FUNCTION) && LCD_W >= 212
  #define TR_SF_SAFETY                 "Override\0 "
#elif defined(OVERRIDE_CHANNEL_FUNCTION)
  #define TR_SF_SAFETY                 "Overr.\0   "
#else
  #define TR_SF_SAFETY                 "---\0      "
#endif

#define TR_SF_SCREENSHOT             "Screenshot"
#define TR_SF_RESERVE                "[reserve]\0"

#define TR_VFSWFUNC                    TR_SF_SAFETY "Trainer\0  ""Inst. Trim""Reset\0    ""Set \0     " TR_ADJUST_GVAR "Volume\0   " "SetFailsfe" "RangeCheck" "ModuleBind" TR_SOUND TR_PLAY_TRACK TR_PLAY_VALUE TR_SF_RESERVE TR_SF_PLAY_SCRIPT TR_SF_RESERVE TR_SF_BG_MUSIC TR_VVARIO TR_HAPTIC TR_SDCLOGS "Backlight\0" TR_SF_SCREENSHOT TR_SF_TEST

#define LEN_VFSWRESET                  TR("\004", "\011")

#define TR_FSW_RESET_TELEM             TR("Telm", "Telemetry")

#if LCD_W >= 212
  #define TR_FSW_RESET_TIMERS          "Timer 1\0 ""Timer 2\0 ""Timer 3\0 "
#else
  #define TR_FSW_RESET_TIMERS          "Tmr1""Tmr2""Tmr3"
#endif

#define TR_VFSWRESET                   TR(TR_FSW_RESET_TIMERS "All\0" TR_FSW_RESET_TELEM, TR_FSW_RESET_TIMERS "Flight\0  " TR_FSW_RESET_TELEM)

#define LEN_FUNCSOUNDS                 TR("\004", "\006")
#define TR_FUNCSOUNDS                  TR("Bp1\0""Bp2\0""Bp3\0""Wrn1""Wrn2""Chee""Rata""Tick""Sirn""Ring""SciF""Robt""Chrp""Tada""Crck""Alrm", "Beep1 ""Beep2 ""Beep3 ""Warn1 ""Warn2 ""Cheep ""Ratata""Tick  ""Siren ""Ring  ""SciFi ""Robot ""Chirp ""Tada  ""Crickt""AlmClk")

#define LEN_VTELEMCHNS                 "\004"

#define LENGTH_UNIT_IMP                "ft\0"
#define SPEED_UNIT_IMP                 "mph"
#define LENGTH_UNIT_METR               "m\0 "
#define SPEED_UNIT_METR                "kmh"

#define LEN_VUNITSSYSTEM               TR("\006", "\010")
#define TR_VUNITSSYSTEM                TR("Metric""Imper.", "Metric\0 ""Imperial")
#define LEN_VTELEMUNIT                 "\003"
#define TR_VTELEMUNIT                  "-\0 ""V\0 ""A\0 ""mA\0""kts""m/s""f/s""kmh""mph""m\0 ""ft\0""@C\0""@F\0""%\0 ""mAh""W\0 ""mW\0""dB\0""rpm""g\0 ""@\0 ""rad""ml\0""fOz""mlm"

#define STR_V                          (STR_VTELEMUNIT+1)
#define STR_A                          (STR_VTELEMUNIT+4)

#define LEN_VTELEMSCREENTYPE           "\006"
#define TR_VTELEMSCREENTYPE            "None\0 ""Nums\0 ""Bars\0 ""Script"

#define LEN_GPSFORMAT                  "\004"
#define TR_GPSFORMAT                   "DMS\0""NMEA"

#define LEN2_VTEMPLATES                12
#define LEN_VTEMPLATES                 "\014"
#define TR_TEMPLATE_CLEAR_MIXES        "Clear Mixes "
#define TR_TEMPLATE_SIMPLE_4CH         "Simple 4-CH "
#define TR_TEMPLATE_STICKY_TCUT        "Sticky-T-Cut"
#define TR_TEMPLATE_VTAIL              "V-Tail      "
#define TR_TEMPLATE_DELTA              "Elevon\\Delta"
#define TR_TEMPLATE_ECCPM              "eCCPM       "
#define TR_TEMPLATE_HELI               "Heli Setup  "
#define TR_TEMPLATE_SERVO_TEST         "Servo Test  "

#define LEN_VSWASHTYPE                 "\004"
#define TR_VSWASHTYPE                  "---\0""120\0""120X""140\0""90\0"

#if defined(PCBHORUS)
  #define LEN_VKEYS                    "\005"
  #define TR_VKEYS                     "PGUP\0""PGDN\0""ENTER""MDL\0 ""RTN\0 ""TELE\0""SYS\0 "
#elif defined(PCBXLITE)
  #define LEN_VKEYS                    "\005"
  #define TR_VKEYS                     "Shift""Exit\0""Enter""Down\0""Up\0  ""Right""Left\0"
#elif defined(RADIO_T12)
  #define LEN_VKEYS                    "\005"
  #define TR_VKEYS                     "Exit\0""Enter""Down\0""Up\0  ""Right""Left\0"
#elif defined(PCBTARANIS)
  #define LEN_VKEYS                    "\005"
  #define TR_VKEYS                     "Menu\0""Exit\0""Enter""Page\0""Plus\0""Minus"
#else
  #define LEN_VKEYS                    "\005"
  #define TR_VKEYS                     "Menu\0""Exit\0""Down\0""Up\0  ""Right""Left\0"
#endif

#define LEN_VSWITCHES                  "\003"
#define LEN_VSRCRAW                    "\004"

#define TR_STICKS_VSRCRAW              "\307Rud""\307Ele""\307Thr""\307Ail"

#if defined(PCBHORUS)
  #define TR_TRIMS_VSRCRAW             "\313Rud""\313Ele""\313Thr""\313Ail""\313T5\0""\313T6\0"
#else
  #define TR_TRIMS_VSRCRAW             "\313Rud""\313Ele""\313Thr""\313Ail"
#endif

#if defined(PCBHORUS)
  #define TR_TRIMS_SWITCHES            "\313Rl""\313Rr""\313Ed""\313Eu""\313Td""\313Tu""\313Al""\313Ar""\3135d""\3135u""\3136d""\3136u"
#else
  #define TR_TRIMS_SWITCHES            TR("tRl""tRr""tEd""tEu""tTd""tTu""tAl""tAr", "\313Rl""\313Rr""\313Ed""\313Eu""\313Td""\313Tu""\313Al""\313Ar")
#endif

#if defined(PCBSKY9X)
  #define TR_ROTARY_ENCODERS           "REa\0"
  #define TR_ROTENC_SWITCHES           "REa"
#else
  #define TR_ROTARY_ENCODERS
  #define TR_ROTENC_SWITCHES
#endif

#define TR_ON_ONE_SWITCHES             "ON\0""One"

#if defined(GYRO)
  #define TR_GYR_VSRCRAW               "GyrX""GyrY"
#else
  #define TR_GYR_VSRCRAW
#endif

#if defined(HELI)
  #define TR_CYC_VSRCRAW               "CYC1""CYC2""CYC3"
#else
  #define TR_CYC_VSRCRAW               "[C1]""[C2]""[C3]"
#endif

#define TR_RESERVE_VSRCRAW           "[--]"
#define TR_EXTRA_VSRCRAW             "Batt""Time""GPS\0" TR_RESERVE_VSRCRAW TR_RESERVE_VSRCRAW TR_RESERVE_VSRCRAW TR_RESERVE_VSRCRAW "Tmr1""Tmr2""Tmr3"

#define LEN_VTMRMODES                  "\003"
#define TR_VTMRMODES                   "OFF""ON\0""THs""TH%""THt"

#define LEN_VTRAINERMODES              "\022"
#define TR_VTRAINER_MASTER_JACK        "Master/Jack\0      "
#define TR_VTRAINER_SLAVE_JACK         "Slave/Jack\0       "
#define TR_VTRAINER_MASTER_SBUS_MODULE "Master/SBUS Module"
#define TR_VTRAINER_MASTER_CPPM_MODULE "Master/CPPM Module"
#define TR_VTRAINER_MASTER_BATTERY     "Master/Serial\0    "
#define TR_VTRAINER_BLUETOOTH          TR("Master/BT\0        ""Slave/BT\0         ", "Master/Bluetooth\0 ""Slave/Bluetooth\0  ")
#define TR_VTRAINER_MULTI              "Master/Multi"

#define LEN_VFAILSAFE                  "\011"
#define TR_VFAILSAFE                   "Not set\0 ""Hold\0    ""Custom\0  ""No pulses""Receiver\0"


#define LEN_VSENSORTYPES               "\012"
#define TR_VSENSORTYPES                "Custom\0   ""Calculated"

#define LEN_VFORMULAS                  "\010"
#define TR_VFORMULAS                   "Add\0    ""Average\0""Min\0    ""Max\0    ""Multiply""Totalize""Cell\0   ""Consumpt""Distance"

#define LEN_VPREC                      "\004"
#define TR_VPREC                       "0.--""0.0 ""0.00"

#define LEN_VCELLINDEX                 "\007"
#define TR_VCELLINDEX                  "Lowest\0""1\0     ""2\0     ""3\0     ""4\0     ""5\0     ""6\0     ""Highest""Delta\0"

#define LEN_GYROS                      "\004"
#define TR_GYROS                       "GyrX""GyrY"

// ZERO TERMINATED STRINGS
#if defined(COLORLCD)
  #define INDENT                       "   "
  #define LEN_INDENT                   3
  #define INDENT_WIDTH                 12
  #define BREAKSPACE                   "\036"
#else
  #define INDENT                       "\001"
  #define LEN_INDENT                   1
  #define INDENT_WIDTH                 (FW/2)
  #define BREAKSPACE                   " "
#endif

#if defined(PCBTARANIS) || defined(PCBHORUS)
  #define TR_ENTER                     "[ENTER]"
#else
  #define TR_ENTER                     "[MENU]"
#endif

#if defined(PCBHORUS)
  #define TR_EXIT                      "[RTN]"
  #define TR_OK                        TR_ENTER
#else
  #define TR_EXIT                      "[EXIT]"
  #define TR_OK                        TR("\010" "\010" "\010" "[OK]", "\010" "\010" "\010" "\010" "\010" "[OK]")
#endif

#if defined(PCBTARANIS)
  #define TR_POPUPS_ENTER_EXIT         TR(TR_EXIT "\010" TR_ENTER, TR_EXIT "\010" "\010" "\010" "\010" TR_ENTER)
#else
  #define TR_POPUPS_ENTER_EXIT         TR_ENTER "\010" TR_EXIT
#endif

#define TR_FREE                        "free"
#define TR_DELETEMODEL                 "DELETE" BREAKSPACE "MODEL"
#define TR_COPYINGMODEL                "Copying model..."
#define TR_MOVINGMODEL                 "Moving model..."
#define TR_LOADINGMODEL                "Loading model..."
#define TR_NAME                        "Name"
#define TR_MODELNAME                   "Model name"
#define TR_PHASENAME                   "Mode name"
#define TR_MIXNAME                     "Mix name"
#define TR_INPUTNAME                   TR("Input", "Input name")
#define TR_EXPONAME                    TR("Name", "Line name")
#define TR_BITMAP                      "Model image"
#define TR_TIMER                       TR("Timer", "Timer ")
#define TR_ELIMITS                     TR("E.Limits", "Extended limits")
#define TR_ETRIMS                      TR("E.Trims", "Extended trims")
#define TR_TRIMINC                     "Trim Step"
#define TR_DISPLAY_TRIMS               TR("Show Trims", "Display trims")
#define TR_TTRACE                      TR("T-Source", INDENT "Source")
#define TR_TTRIM                       TR("T-Trim", INDENT "Trim idle only")
#define TR_BEEPCTR                     TR("Ctr Beep", "Center Beep")
#define TR_USE_GLOBAL_FUNCS            TR("Glob.Funcs", "Use global funcs")
#if defined(PCBSKY9X) && defined(REVX)
  #define TR_OUTPUT_TYPE               INDENT "Output"
#endif
#define TR_PROTO                       TR(INDENT "Proto", INDENT "Protocol")
  #define TR_PPMFRAME                  INDENT "PPM frame"
  #define TR_REFRESHRATE               TR(INDENT "Refresh", INDENT "Refresh rate")
  #define STR_WARN_BATTVOLTAGE         TR(INDENT "Output is VBAT: ", INDENT "Warning: output level is VBAT: ")
#define TR_MS                          "ms"
#define TR_FREQUENCY                   INDENT "Frequency"
#define TR_SWITCH                      "Switch"
#define TR_TRIMS                       "Trims"
#define TR_FADEIN                      "Fade in"
#define TR_FADEOUT                     "Fade out"
#define TR_DEFAULT                     "(default)"
#define TR_CHECKTRIMS                  CENTER "\006Check\012trims"
#define OFS_CHECKTRIMS                 CENTER_OFS+(9*FW)
#define TR_SWASHTYPE                   "Swash Type"
#define TR_COLLECTIVE                  TR("Collective", "Coll. pitch source")
#define TR_AILERON                     TR("Lateral cyc.", "Lateral cyc. source")
#define TR_ELEVATOR                    TR("Long. cyc.", "Long. cyc. source")
#define TR_SWASHRING                   "Swash Ring"
#define TR_ELEDIRECTION                "ELE Direction"
#define TR_AILDIRECTION                "AIL Direction"
#define TR_COLDIRECTION                "PIT Direction"
#define TR_MODE                        "Mode"
#define TR_SUBTYPE                     INDENT "Subtype"
#define TR_NOFREEEXPO                  "No free expo!"
#define TR_NOFREEMIXER                 "No free mixer!"
#define TR_SOURCE                       "Source"
#define TR_WEIGHT                      "Weight"
#define TR_EXPO                        TR("Expo", "Exponential")
#define TR_SIDE                        "Side"
#define TR_DIFFERENTIAL                "Differ"
#define TR_OFFSET                       "Offset"
#define TR_TRIM                        "Trim"
#define TR_DREX                        "DRex"
#define DREX_CHBOX_OFFSET              30
#define TR_CURVE                       "Curve"
#define TR_FLMODE                      TR("Mode", "Modes")
#define TR_MIXWARNING                  "Warning"
#define TR_OFF                         "OFF"
#define TR_ANTENNA                     "Antenna"
#define TR_NO_INFORMATION              TR("No info", "No information")
#define TR_MULTPX                      "Multiplex"
#define TR_DELAYDOWN                   "Delay dn"
#define TR_DELAYUP                     "Delay up"
#define TR_SLOWDOWN                    "Slow  dn"
#define TR_SLOWUP                      "Slow  up"
#define TR_MIXES                       "MIXES"
#define TR_CV                          "CV"
#define TR_GV                          TR("G", "GV")
#define TR_ACHANNEL                    "A\004channel"
#define TR_RANGE                       INDENT "Range"
#define TR_CENTER                      INDENT "Center"
#define TR_BAR                         "Bar"
#define TR_ALARM                       INDENT "Alarm"
#define TR_USRDATA                     TR("UsrData", "User data")
#define TR_BLADES                      INDENT "Blades/Poles"
#define TR_SCREEN                      "Screen\001"
#define TR_SOUND_LABEL                 "Sound"
#define TR_LENGTH                      INDENT "Length"
#define TR_BEEP_LENGTH                 INDENT "Beep length"
#define TR_SPKRPITCH                   INDENT "Beep pitch"
#define TR_HAPTIC_LABEL                "Haptic"
#define TR_HAPTICSTRENGTH              INDENT "Strength"
#define TR_GYRO_LABEL                  "Gyro"
#define TR_GYRO_OFFSET                 "Offset"
#define TR_GYRO_MAX                    "Max"
#define TR_CONTRAST                    "Contrast"
#define TR_ALARMS_LABEL                "Alarms"
#define TR_BATTERY_RANGE               TR("Batt. range", "Battery meter range")
#define TR_BATTERYWARNING              INDENT "Battery low"
#define TR_INACTIVITYALARM             INDENT "Inactivity"
#define TR_MEMORYWARNING               INDENT "Memory low"
#define TR_ALARMWARNING                INDENT "Sound off"
#define TR_RSSISHUTDOWNALARM           TR(INDENT "Rssi Shutdown", INDENT "Check RSSI on shutdown")
#define TR_MODEL_STILL_POWERED         "Model still powered"
#define TR_MODEL_SHUTDOWN              "Shutdown?"
#define TR_PRESS_ENTER_TO_CONFIRM      "Press enter to confirm"
#define TR_THROTTLE_LABEL              "Throttle"
#define TR_THROTTLEREVERSE             TR("T-Reverse", INDENT "Reverse")
#define TR_MINUTEBEEP                  TR("Minute", "Minute call")
#define TR_BEEPCOUNTDOWN               INDENT "Countdown"
#define TR_PERSISTENT                  TR(INDENT "Persist.", INDENT "Persistent")
#define TR_BACKLIGHT_LABEL             "Backlight"
#define TR_BLDELAY                     INDENT "Duration"
#define TR_BLONBRIGHTNESS              INDENT "ON brightness"
#define TR_BLOFFBRIGHTNESS             INDENT "OFF brightness"
#define TR_BLCOLOR                     INDENT "Color"
#define TR_SPLASHSCREEN                "Splash screen"
#define TR_PWR_ON_DELAY                "Pwr On delay"
#define TR_PWR_OFF_DELAY               "Pwr Off delay"
#define TR_THROTTLEWARNING             TR(INDENT "T-Warning", INDENT "Throttle state")
#define TR_SWITCHWARNING               TR(INDENT "S-Warning", INDENT "Switch positions")
#define TR_POTWARNINGSTATE             TR(INDENT "Pot&Slid.", INDENT "Pots & sliders")
#define TR_SLIDERWARNING               TR(INDENT "Slid. pos.", INDENT "Slider positions")
#define TR_POTWARNING                  TR(INDENT "Pot warn.", INDENT "Pot positions")
#define TR_TIMEZONE                    TR("Time Zone", INDENT "Time zone")
#define TR_ADJUST_RTC                  TR("Adjust RTC", INDENT "Adjust RTC")
#define TR_GPS                         "GPS"
#define TR_RXCHANNELORD                TR("Rx channel ord", "Default channel order")
#define TR_STICKS                      "Sticks"
#define TR_POTS                        "Pots"
#define TR_SWITCHES                    "Switches"
#define TR_SWITCHES_DELAY              TR("Play delay", "Play delay (sw. mid pos)")
#define TR_SLAVE                       CENTER "Slave"
#define TR_MODESRC                     "Mode\006% Source"
#define TR_MULTIPLIER                  "Multiplier"
#define TR_CAL                         "Cal"
#define TR_VTRIM                       "Trim- +"
#define TR_BG                          "BG:"
#if defined(PCBHORUS)
  #define TR_MENUTOSTART               "Press [Enter] to start"
  #define TR_SETMIDPOINT               "Center sticks/pots/sliders and press [Enter]"
  #define TR_MOVESTICKSPOTS            "Move sticks/pots/sliders and press [Enter]"
#elif defined(COLORLCD)
  #define TR_MENUTOSTART               TR_ENTER " TO START"
  #define TR_SETMIDPOINT               "CENTER STICKS/SLIDERS"
  #define TR_MOVESTICKSPOTS            "MOVE STICKS/POTS"
  #define TR_MENUWHENDONE              TR_ENTER " WHEN DONE"
#else
  #define TR_MENUTOSTART               CENTER "\010" TR_ENTER " TO START"
  #define TR_SETMIDPOINT               TR(CENTER "\004SET STICKS MIDPOINT", CENTER "\004CENTER STICKS/SLIDERS")
  #define TR_MOVESTICKSPOTS            CENTER "\006MOVE STICKS/POTS"
  #define TR_MENUWHENDONE              CENTER "\006" TR_ENTER " WHEN DONE"
#endif
#define TR_RXBATT                      "Rx Batt:"
#define TR_TXnRX                       "Tx:\0Rx:"
#define OFS_RX                         4
#define TR_ACCEL                       "Acc:"
#define TR_NODATA                      CENTER "NO DATA"
#define TR_US                          "us"
#define TR_TMIXMAXMS                   "Tmix max"
#define TR_FREE_STACK                  "Free stack"
#define TR_MENUTORESET                 TR_ENTER " to reset"
#define TR_PPM_TRAINER                 "TR"
#define TR_CH                          "CH"
#define TR_MODEL                       "MODEL"
#define TR_FM                          "FM"
#define TR_MIX                         "MIX"
#define TR_EEPROMLOWMEM                "EEPROM low mem"
#define TR_ALERT                       "\016ALERT"
#define TR_PRESSANYKEYTOSKIP           "Press any key to skip"
#define TR_THROTTLENOTIDLE             "Throttle not idle"
#define TR_ALARMSDISABLED              "Alarms disabled"
#define TR_PRESSANYKEY                 TR("\010Press any Key", "Press any key")
#define TR_BADEEPROMDATA               "Bad EEprom data"
#define TR_BAD_RADIO_DATA              "Bad radio data"
#define TR_EEPROMFORMATTING            "Formatting EEPROM"
#define TR_STORAGE_FORMAT              "Storage preparation"
#define TR_EEPROMOVERFLOW              "EEPROM overflow"
#define TR_MENURADIOSETUP              "RADIO SETUP"
#define TR_MENUDATEANDTIME             "DATE AND TIME"
#define TR_MENUTRAINER                 "TRAINER"
#define TR_MENUSPECIALFUNCS            "GLOBAL FUNCTIONS"
#define TR_MENUVERSION                 "VERSION"
#define TR_MENU_RADIO_SWITCHES         TR("SWITCHES", "SWITCHES TEST")
#define TR_MENU_RADIO_ANALOGS          TR("ANALOGS", "ANALOGS TEST")
#define TR_MENUCALIBRATION             "CALIBRATION"
#if defined(COLORLCD)
  #define TR_TRIMS2OFFSETS             "Trims => Subtrims"
#else
  #define TR_TRIMS2OFFSETS             "\006Trims => Subtrims"
#endif
#define TR_CHANNELS2FAILSAFE           "Channels=>Failsafe"
#define TR_CHANNEL2FAILSAFE            "Channel=>Failsafe"
#define TR_MENUMODELSEL                TR("MODELSEL", "MODEL SELECTION")
#define TR_MENUSETUP                   TR("SETUP", "MODEL SETUP")
#define TR_MENUFLIGHTMODES             "FLIGHT MODES"
#define TR_MENUFLIGHTMODE              "FLIGHT MODE"
#define TR_MENUHELISETUP               "HELI SETUP"

  #define TR_MENUINPUTS                "INPUTS"
  #define TR_MENULIMITS                "OUTPUTS"
#define TR_MENUCURVES                  "CURVES"
#define TR_MENUCURVE                   "CURVE"
#define TR_MENULOGICALSWITCH           "LOGICAL SWITCH"
#define TR_MENULOGICALSWITCHES         "LOGICAL SWITCHES"
#define TR_MENUCUSTOMFUNC              "SPECIAL FUNCTIONS"
#define TR_MENUCUSTOMSCRIPTS           "CUSTOM SCRIPTS"
#define TR_MENUTELEMETRY               "TELEMETRY"
#define TR_MENUTEMPLATES               "TEMPLATES"
#define TR_MENUSTAT                    "STATS"
#define TR_MENUDEBUG                   "DEBUG"
#define TR_MONITOR_CHANNELS1           "CHANNELS MONITOR 1-8"
#define TR_MONITOR_CHANNELS2           "CHANNELS MONITOR 9-16"
#define TR_MONITOR_CHANNELS3           "CHANNELS MONITOR 17-24"
#define TR_MONITOR_CHANNELS4           "CHANNELS MONITOR 25-32"
#define TR_MONITOR_SWITCHES            "LOGICAL SWITCHES MONITOR"
#define TR_MONITOR_OUTPUT_DESC         "Outputs"
#define TR_MONITOR_MIXER_DESC          "Mixers"
  #define TR_RECEIVER_NUM              TR("RxNum", "Receiver No.")
  #define TR_RECEIVER                  "Receiver"
#define TR_MULTI_RFTUNE                TR("Freq tune", "RF Freq. fine tune")
#define TR_MULTI_TELEMETRY             "Telemetry"
#define TR_MULTI_VIDFREQ               TR("Vid. freq.", "Video frequency")
#define TR_RFPOWER                     "RF Power"
#define TR_MULTI_FIXEDID               TR("FixedID", "Fixed ID")
#define TR_MULTI_OPTION                TR("Option", "Option value")
#define TR_MULTI_AUTOBIND              TR(INDENT "Bind Ch.",INDENT "Bind on channel")
#define TR_DISABLE_CH_MAP              TR("No Ch. map", "Disable Ch. map")
#define TR_DISABLE_TELEM               TR("No Telem", "Disable Telemetry")
#define TR_MULTI_DSM_AUTODTECT         TR(INDENT "Autodetect", INDENT "Autodetect format")
#define TR_MULTI_LOWPOWER              TR(INDENT "Low power", INDENT "Low power mode")
#define TR_MODULE_TELEMETRY            TR(INDENT "S.Port", INDENT "S.Port link")
#define TR_MODULE_TELEM_ON             TR("ON", "Enabled")
#define TR_DISABLE_INTERNAL            TR("Disable int.", "Disable internal RF")
#define TR_MODULE_NO_SERIAL_MODE       TR("!serial mode", "Not in serial mode")
#define TR_MODULE_NO_INPUT             TR("No input", "No serial input")
#define TR_MODULE_NO_TELEMETRY         TR3("No telemetry", "No MULTI_TELEMETRY", "No MULTI_TELEMETRY detected")
#define TR_MODULE_WAITFORBIND          "Bind to load protocol"
#define TR_MODULE_BINDING              TR("Bind...","Binding")
#define TR_MODULE_UPGRADE_ALERT        TR3("Upg. needed", "Module upgrade required", "Module\036Upgrade required")
#define TR_MODULE_UPGRADE              TR("Upg. advised", "Module update recommended")
#define TR_REBIND                      "Rebinding required"
#define TR_REG_OK                      "Registration ok"
#define TR_BIND_OK                     "Bind successful"
#define TR_BINDING_CH1_8_TELEM_ON      "Ch1-8 Telem ON"
#define TR_BINDING_CH1_8_TELEM_OFF     "Ch1-8 Telem OFF"
#define TR_BINDING_CH9_16_TELEM_ON     "Ch9-16 Telem ON"
#define TR_BINDING_CH9_16_TELEM_OFF    "Ch9-16 Telem OFF"
#define TR_PROTOCOL_INVALID            TR("Prot. invalid", "Protocol invalid")
#define TR_MODULE_STATUS               TR(INDENT "Status", INDENT "Module Status")
#define TR_MODULE_SYNC                 TR(INDENT "Sync", INDENT "Proto Sync Status")
#define TR_MULTI_SERVOFREQ             TR("Servo rate", "Servo update rate")
#define TR_MULTI_MAX_THROW             TR("Max. Throw", "Enable max. throw")
#define TR_MULTI_RFCHAN                TR("RF Channel", "Select RF channel")
#define TR_SYNCMENU                    "[Sync]"
#define TR_LIMIT                       INDENT "Limit"
#define TR_MINRSSI                     "Min Rssi"
#define TR_LATITUDE                    "Latitude"
#define TR_LONGITUDE                   "Longitude"
#define TR_GPSCOORD                    TR("GPS Coords", INDENT "Coordinate format")
#define TR_VARIO                       TR("Vario", "Variometer")
#define TR_PITCH_AT_ZERO               INDENT "Pitch zero"
#define TR_PITCH_AT_MAX                INDENT "Pitch max"
#define TR_REPEAT_AT_ZERO              INDENT "Repeat zero"
#define TR_SHUTDOWN                    "SHUTTING DOWN"
#define TR_SAVEMODEL                   "Saving model settings"
#define TR_BATT_CALIB                  TR("Batt. calib", "Battery calibration")
#define TR_CURRENT_CALIB               "Current calib"
#define TR_VOLTAGE                     TR(INDENT "Voltage", INDENT "Voltage source")
#define TR_CURRENT                     TR(INDENT "Current", INDENT "Current source")
#define TR_SELECT_MODEL                "Select model"
#define TR_CREATE_CATEGORY             "Create category"
#define TR_RENAME_CATEGORY             "Rename category"
#define TR_DELETE_CATEGORY             "Delete category"
#define TR_CREATE_MODEL                "Create model"
#define TR_DUPLICATE_MODEL             "Duplicate model"
#define TR_COPY_MODEL                  "Copy model"
#define TR_MOVE_MODEL                  "Move model"
#define TR_BACKUP_MODEL                "Backup model"
#define TR_DELETE_MODEL                "Delete model"
#define TR_RESTORE_MODEL               "Restore model"
#define TR_DELETE_ERROR                "Delete error"
#define TR_CAT_NOT_EMPTY               "Category is not empty"
#define TR_SDCARD_ERROR                TR("SD error", "SD card error")
#define TR_NO_SDCARD                   "No SD card"
#define TR_WAITING_FOR_RX              "Waiting for RX..."
#define TR_WAITING_FOR_TX              "Waiting for TX..."
#define TR_NO_TOOLS                    "No tools available"
#define TR_NORMAL                      "Normal"
#define TR_NOT_INVERTED                "Not inv"
#define TR_NOT_CONNECTED               "!Connected"
#define TR_CONNECTED                   "Connected"
#define TR_FLEX_915                    "Flex 915MHz"
#define TR_FLEX_868                    "Flex 868MHz"
#define TR_16CH_WITHOUT_TELEMETRY      TR("16CH without telem.", "16CH without telemetry")
#define TR_16CH_WITH_TELEMETRY         TR("16CH with telem.", "16CH with telemetry")
#define TR_8CH_WITH_TELEMETRY          TR("8CH with telem.", "8CH with telemetry")
#define TR_EXT_ANTENNA                 "Ext. antenna"
#define TR_PIN                         "Pin"
#define TR_UPDATE_RX_OPTIONS           "Update RX options?"
#define TR_UPDATE_TX_OPTIONS           "Update TX options?"
#define TR_MODULES_RX_VERSION          "Modules / RX version"
#define TR_MENU_MODULES_RX_VERSION     "MODULES / RX VERSION"
#define TR_MENU_FIRM_OPTIONS           "FIRMWARE OPTIONS"
#define TR_GYRO                        "Gyro"
#define TR_STICKS_POTS_SLIDERS         "Sticks/Pots/Sliders"
#define TR_PWM_STICKS_POTS_SLIDERS     "PWM Sticks/Pots/Sliders"
#define TR_RF_PROTOCOL                 "RF Protocol"
#define TR_MODULE_OPTIONS              "Module options"
#define TR_POWER                       "Power"
#define TR_NO_TX_OPTIONS               "No TX options"
#define TR_RTC_BATT                    "RTC Batt"
#define TR_POWER_METER_EXT             "Power Meter (EXT)"
#define TR_POWER_METER_INT             "Power Meter (INT)"
#define TR_SPECTRUM_ANALYSER_EXT       "Spectrum (EXT)"
#define TR_SPECTRUM_ANALYSER_INT       "Spectrum (INT)"
#define TR_SDCARD_FULL                 "SD card full"
#define TR_NEEDS_FILE                  "NEEDS FILE"
#define TR_EXT_MULTI_SPEC              "opentx-inv"
#define TR_INT_MULTI_SPEC              "stm-opentx-noinv"
#define TR_INCOMPATIBLE                "Incompatible"
#define TR_WARNING                     "WARNING"
#define TR_EEPROMWARN                  "EEPROM"
#define TR_STORAGE_WARNING             "STORAGE"
#define TR_EEPROM_CONVERTING           "Converting EEPROM"
#define TR_THROTTLEWARN                "THROTTLE"
#define TR_ALARMSWARN                  "ALARMS"
#define TR_SWITCHWARN                  TR("SWITCH", "CONTROL")
#define TR_FAILSAFEWARN                "FAILSAFE"
#define TR_TEST_WARNING                 TR("TESTING", "TEST BUILD")
#define TR_TEST_NOTSAFE                 "Use for tests only"
#define TR_WRONG_SDCARDVERSION         TR("Expected ver: ","Expected version: ")
#define TR_WARN_RTC_BATTERY_LOW        "RTC Battery low"
#define TR_WARN_MULTI_LOWPOWER         "Low power mode"
#define TR_BATTERY                     "BATTERY"
#define TR_WRONG_PCBREV                "Wrong PCB detected"
#define TR_EMERGENCY_MODE              "EMERGENCY MODE"
#define TR_PCBREV_ERROR                "PCB error"
#define TR_NO_FAILSAFE                 "Failsafe not set"
#define TR_KEYSTUCK                    "Key stuck"
#define TR_INVERT_THR                  TR("Invert thr?", "Invert throttle?")
#define TR_SPEAKER_VOLUME              INDENT "Volume" // TODO could be TR_VOLUME ?
#define TR_LCD                         "LCD"
#define TR_BRIGHTNESS                  INDENT "Brightness"
#define TR_CPU_TEMP                    "CPU temp."
#define TR_CPU_CURRENT                 "Current"
#define TR_CPU_MAH                     "Consumpt."
#define TR_COPROC                      "CoProc."
#define TR_COPROC_TEMP                 "MB Temp."
#define TR_CAPAWARNING                 INDENT "Capacity low"
#define TR_TEMPWARNING                 INDENT "Overheat"
#define TR_FUNC                        "Func"
#define TR_V1                          "V1"
#define TR_V2                          "V2"
#define TR_DURATION                    "Duration"
#define TR_DELAY                       "Delay"
#define TR_SD_CARD                     "SD CARD"
#define TR_SDHC_CARD                   "SD-HC CARD"
#define TR_NO_SOUNDS_ON_SD             "No sounds" BREAKSPACE "on SD"
#define TR_NO_MODELS_ON_SD             "No models" BREAKSPACE "on SD"
#define TR_NO_BITMAPS_ON_SD            "No bitmaps" BREAKSPACE "on SD"
#define TR_NO_SCRIPTS_ON_SD            "No scripts" BREAKSPACE "on SD"
#define TR_SCRIPT_SYNTAX_ERROR         "Script syntax error"
#define TR_SCRIPT_PANIC                "Script panic"
#define TR_SCRIPT_KILLED               "Script killed"
#define TR_SCRIPT_ERROR                "Unknown error"
#define TR_PLAY_FILE                   "Play"
#define TR_DELETE_FILE                 "Delete"
#define TR_COPY_FILE                   "Copy"
#define TR_RENAME_FILE                 "Rename"
#define TR_ASSIGN_BITMAP               "Assign bitmap"
#define TR_ASSIGN_SPLASH               "Splash screen"
#define TR_EXECUTE_FILE                "Execute"
#define TR_REMOVED                     " removed"
#define TR_SD_INFO                     "Information"
#define TR_SD_FORMAT                   "Format"
#define TR_NA                          "N/A"
#define TR_HARDWARE                    "HARDWARE"
#define TR_FORMATTING                  "Formatting..."
#define TR_TEMP_CALIB                  "Temp. Calib"
#define TR_TIME                        "Time"
#define TR_MAXBAUDRATE                 "Max bauds"
#define TR_BLUETOOTH                   "Bluetooth"
#define TR_BLUETOOTH_DISC              "Discover"
#define TR_BLUETOOTH_INIT              "Init"
#define TR_BLUETOOTH_DIST_ADDR         "Dist addr"
#define TR_BLUETOOTH_LOCAL_ADDR        "Local addr"
#define TR_BLUETOOTH_PIN_CODE          "PIN code"
#define TR_BAUDRATE                    "BT Baudrate"
#define LEN_BLUETOOTH_MODES            "\011"
#if defined(PCBX9E)
#define TR_BLUETOOTH_MODES             "---\0     ""Enabled\0 "
#else
#define TR_BLUETOOTH_MODES             "---\0     ""Telemetry""Trainer\0"
#endif

#define TR_SD_INFO_TITLE               "SD INFO"
#define TR_SD_TYPE                     "Type:"
#define TR_SD_SPEED                    "Speed:"
#define TR_SD_SECTORS                  "Sectors:"
#define TR_SD_SIZE                     "Size:"
#define TR_TYPE                        INDENT "Type"
#define TR_GLOBAL_VARS                 "Global variables"
#define TR_GVARS                       "GVARS"
#define TR_GLOBAL_VAR                  "Global variable"
#define TR_MENUGLOBALVARS              "GLOBAL VARIABLES"
#define TR_OWN                         "Own"
#define TR_DATE                        "Date"
#define TR_MONTHS                      { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" }
#define TR_ROTARY_ENCODER              "R.E."
#define TR_CHANNELS_MONITOR            "CHANNELS MONITOR"
#define TR_MIXERS_MONITOR              "MIXERS MONITOR"
#define TR_PATH_TOO_LONG               "Path too long"
#define TR_VIEW_TEXT                   "View text"
#define TR_FLASH_BOOTLOADER            "Flash bootloader"
#define TR_FLASH_EXTERNAL_DEVICE       TR("Flash S.Port", "Flash S.Port device")
#define TR_FLASH_RECEIVER_OTA          "Flash receiver OTA"
#define TR_FLASH_BLUETOOTH_MODULE      TR("Flash BT module", "Flash Bluetooth module")
#define TR_FLASH_POWER_MANAGEMENT_UNIT "Flash pwr mngt unit"
#define TR_CURRENT_VERSION             TR("Curr Vers: ", "Current version: ")
#define TR_FLASH_INTERNAL_MODULE       TR("Flash int. module", "Flash internal module")
#define TR_FLASH_INTERNAL_MULTI        TR("Flash Int. Multi", "Flash Internal Multi")
#define TR_FLASH_EXTERNAL_MODULE       TR("Flash ext. module", "Flash external module")
#define TR_FLASH_EXTERNAL_MULTI        TR("Flash Ext. Multi", "Flash External Multi")
#define TR_FIRMWARE_UPDATE_ERROR       TR("FW update error", "Firmware update error")
#define TR_FIRMWARE_UPDATE_SUCCESS     "Flash successful"
#define TR_WRITING                     "Writing..."
#define TR_CONFIRM_FORMAT              "Confirm Format?"
#define TR_INTERNALRF                  "Internal RF"
#define TR_INTERNAL_MODULE             TR("Int. module","Internal module")
#define TR_EXTERNAL_MODULE             TR("Ext. module","External module")
#define TR_OPENTX_UPGRADE_REQUIRED     "OpenTX upgrade required"
#define TR_TELEMETRY_DISABLED          "Telem. disabled"
#define TR_MORE_OPTIONS_AVAILABLE      "More options available"
#define TR_NO_MODULE_INFORMATION       "No module information"
#define TR_EXTERNALRF                  "External RF"
#define TR_FAILSAFE                    TR(INDENT "Failsafe", INDENT "Failsafe mode")
#define TR_FAILSAFESET                 "FAILSAFE SETTINGS"
#define TR_REG_ID                      "Reg. ID"
#define TR_OWNER_ID                    "Owner ID"
#define TR_PINMAPSET                   "PINMAP"
#define TR_HOLD                        "Hold"
#define TR_HOLD_UPPERCASE              "HOLD"
#define TR_NONE                        "None"
#define TR_NONE_UPPERCASE              "NONE"
#define TR_MENUSENSOR                  "SENSOR"
#define TR_POWERMETER_PEAK             "Peak"
#define TR_POWERMETER_POWER            "Power"
#define TR_POWERMETER_ATTN             "Attn"
#define TR_POWERMETER_FREQ             "Freq."
#define TR_MENUTOOLS                   "TOOLS"
#define TR_TURN_OFF_RECEIVER           "Turn off receiver"
#define TR_STOPPING                    "Stopping..."
#define TR_MENU_SPECTRUM_ANALYSER      "SPECTRUM ANALYSER"
#define TR_MENU_POWER_METER            "POWER METER"
#define TR_SENSOR                      "SENSOR"
#define TR_COUNTRYCODE                 "Country code"
#define TR_USBMODE                     "USB Mode"
#define TR_JACKMODE                    "Jack Mode"
#define TR_VOICELANG                   "Voice language"
#define TR_UNITSSYSTEM                 "Units"
#define TR_EDIT                        "Edit"
#define TR_INSERT_BEFORE               "Insert Before"
#define TR_INSERT_AFTER                "Insert After"
#define TR_COPY                        "Copy"
#define TR_MOVE                        "Move"
#define TR_PASTE                       "Paste"
#define TR_DELETE                      "Delete"
#define TR_INSERT                      "Insert"
#define TR_RESET_FLIGHT                "Reset flight"
#define TR_RESET_TIMER1                "Reset timer1"
#define TR_RESET_TIMER2                "Reset timer2"
#define TR_RESET_TIMER3                "Reset timer3"
#define TR_RESET_TELEMETRY             "Reset telemetry"
#define TR_STATISTICS                  "Statistics"
#define TR_ABOUT_US                    "About"
#define TR_USB_JOYSTICK                "USB Joystick (HID)"
#define TR_USB_MASS_STORAGE            "USB Storage (SD)"
#define TR_USB_SERIAL                  "USB Serial (Debug)"
#define TR_SETUP_SCREENS               "Setup screens"
#define TR_MONITOR_SCREENS             "Monitors"
#define TR_AND_SWITCH                  "AND switch"
#define TR_SF                          "SF"
#define TR_GF                          "GF"
#define TR_SPEAKER                     INDENT "Speaker"
#define TR_BUZZER                      INDENT "Buzzer"
#define TR_BYTES                       "bytes"
#define TR_MODULE_BIND                 BUTTON(TR("Bnd", "Bind"))
#define TR_POWERMETER_ATTN_NEEDED      "Attenuator needed"
#define TR_PXX2_SELECT_RX              "Select RX..."
#define TR_PXX2_DEFAULT                "<default>"
#define TR_BT_SELECT_DEVICE            "Select device..."
#define TR_DISCOVER                    "Discover"
#define TR_BUTTON_INIT                 BUTTON("Init")
#define TR_WAITING                     "Waiting..."
#define TR_RECEIVER_DELETE             "Delete receiver?"
#define TR_RECEIVER_RESET              "Reset receiver?"
#define TR_SHARE                       "Share"
#define TR_BIND                        "Bind"
#define TR_REGISTER                    TR("Reg", "Register")
#define TR_MODULE_RANGE                BUTTON(TR("Rng", "Range"))
#define TR_RECEIVER_OPTIONS            TR("REC. OPTIONS", "RECEIVER OPTIONS")
#define TR_DEL_BUTTON                  BUTTON(TR("Del", "Delete"))
#define TR_RESET_BTN                   BUTTON("Reset")
#define TR_DEBUG                       "Debug"
#define TR_KEYS_BTN                    BUTTON(TR("Keys", "Switches"))
#define TR_ANALOGS_BTN                 BUTTON(TR("Anas", "Analogs"))
#define TR_CALIBRATION                 "Calibration"
#define TR_SET                         BUTTON("Set")
#define TR_TRAINER                     "Trainer"
#define TR_CHANS                       "Chans"
#define TR_ANTENNAPROBLEM              CENTER "TX antenna problem!"
#if defined(COLORLCD)
  #define TR_MODELIDUSED               "ID used in:"
#else
  #define TR_MODELIDUSED               TR("ID used in:","Receiver ID used in:")
#endif
#define TR_MODULE                      "Module"
#define TR_RX_NAME                     "Rx Name"
#define TR_TELEMETRY_TYPE              TR("Type", "Telemetry type")
#define TR_TELEMETRY_SENSORS           "Sensors"
#define TR_VALUE                       "Value"
#define TR_TOPLCDTIMER                 "Top LCD Timer"
#define TR_UNIT                        "Unit"
#define TR_TELEMETRY_NEWSENSOR         INDENT "Add a new sensor..."
#define TR_CHANNELRANGE                TR(INDENT "Ch. Range", INDENT "Channel Range")
#define TR_ANTENNACONFIRM1             "EXT. ANTENNA"
#if defined(PCBX12S)
#define LEN_ANTENNA_MODES      "\023"
#define TR_ANTENNA_MODES       "Internal\0          ""Ask\0               ""Per model\0         ""Internal + External"
#else
#define LEN_ANTENNA_MODES      "\011"
#define TR_ANTENNA_MODES       "Internal\0""Ask\0     ""Per model""External"
#endif
#define TR_USE_INTERNAL_ANTENNA        TR("Use int. antenna", "Use internal antenna")
#define TR_USE_EXTERNAL_ANTENNA        TR("Use ext. antenna", "Use external antenna")
#define TR_ANTENNACONFIRM2             TR("Check antenna", "Make sure antenna is installed!")
#define TR_MODULE_PROTOCOL_FLEX_WARN_LINE1   "Requires FLEX non"
#define TR_MODULE_PROTOCOL_FCC_WARN_LINE1    "Requires FCC"
#define TR_MODULE_PROTOCOL_EU_WARN_LINE1     "Requires EU"
#define TR_MODULE_PROTOCOL_WARN_LINE2        "certified firmware"
#define TR_LOWALARM                    INDENT "Low alarm"
#define TR_CRITICALALARM               INDENT "Critical alarm"
#define TR_RSSIALARM_WARN              "RSSI"
#define TR_NO_RSSIALARM                TR(INDENT "Alarms disabled", "Telemetry alarms disabled")
#define TR_DISABLE_ALARM               TR(INDENT "Disable alarms", INDENT "Disable telemetry alarms")
#define TR_ENABLE_POPUP                "Enable popup"
#define TR_DISABLE_POPUP               "Disable popup"
#define TR_POPUP                       "Popup"
#define TR_MIN                         "Min"
#define TR_MAX                         "Max"
#define TR_CURVE_PRESET                "Preset..."
#define TR_PRESET                      "Preset"
#define TR_MIRROR                      "Mirror"
#define TR_CLEAR                       "Clear"
#define TR_RESET                       "Reset"
#define TR_RESET_SUBMENU               "Reset..."
#define TR_COUNT                       "Count"
#define TR_PT                          "pt"
#define TR_PTS                         "pts"
#define TR_SMOOTH                      "Smooth"
#define TR_COPY_STICKS_TO_OFS          TR("Cpy stick->subtrim", "Copy sticks to subtrim")
#define TR_COPY_TRIMS_TO_OFS           TR("Cpy trim->subtrim", "Copy trims to subtrim")
#define TR_INCDEC                      "Inc/Decrement"
#define TR_GLOBALVAR                   "Global var"
#define TR_MIXSOURCE                   "Mixer source"
#define TR_CONSTANT                    "Constant"
#define TR_PERSISTENT_MAH              TR(INDENT "Str mAh", INDENT "Persistent mAh")
#define TR_PREFLIGHT                   "Preflight Checks"
#define TR_CHECKLIST                   TR(INDENT "Checklist", INDENT "Display checklist")
#define TR_FAS_OFFSET                  TR(INDENT "FAS Ofs", INDENT "FAS offset")
#define TR_AUX_SERIAL_MODE                   "Serial port"
#define TR_SCRIPT                      "Script"
#define TR_INPUTS                      "Inputs"
#define TR_OUTPUTS                     "Outputs"
#define STR_EEBACKUP                   "EEPROM backup"
#define STR_FACTORYRESET               "Factory reset"
#define TR_CONFIRMRESET                TR("Erase ALL", "Erase ALL models and settings?")
#define TR_TOO_MANY_LUA_SCRIPTS         "Too many Lua scripts!"

// Horus and Taranis column headers
#define TR_PHASES_HEADERS_NAME         "Name"
#define TR_PHASES_HEADERS_SW           "Switch"
#define TR_PHASES_HEADERS_RUD_TRIM     "Rudder Trim"
#define TR_PHASES_HEADERS_ELE_TRIM     "Elevator Trim"
#define TR_PHASES_HEADERS_THT_TRIM     "Throttle Trim"
#define TR_PHASES_HEADERS_AIL_TRIM     "Aileron Trim"
#define TR_PHASES_HEADERS_CH5_TRIM     "Trim 5"
#define TR_PHASES_HEADERS_CH6_TRIM     "Trim 6"
#define TR_PHASES_HEADERS_FAD_IN       "Fade In"
#define TR_PHASES_HEADERS_FAD_OUT      "Fade Out"

#define TR_LIMITS_HEADERS_NAME         "Name"
#define TR_LIMITS_HEADERS_SUBTRIM      "Subtrim"
#define TR_LIMITS_HEADERS_MIN          "Min"
#define TR_LIMITS_HEADERS_MAX          "Max"
#define TR_LIMITS_HEADERS_DIRECTION    "Direction"
#define TR_LIMITS_HEADERS_CURVE        "Curve"
#define TR_LIMITS_HEADERS_PPMCENTER    "PPM Center"
#define TR_LIMITS_HEADERS_SUBTRIMMODE  "Subtrim mode"

#define TR_LSW_HEADERS_FUNCTION        "Function"
#define TR_LSW_HEADERS_V1              "V1"
#define TR_LSW_HEADERS_V2              "V2"
#define TR_LSW_HEADERS_ANDSW           "AND Switch"
#define TR_LSW_HEADERS_DURATION        "Min Duration"
#define TR_LSW_HEADERS_DELAY           "Delay"

#define TR_GVAR_HEADERS_NAME           "Name"
#define TR_GVAR_HEADERS_FM0            "Value on FM0"
#define TR_GVAR_HEADERS_FM1            "Value on FM1"
#define TR_GVAR_HEADERS_FM2            "Value on FM2"
#define TR_GVAR_HEADERS_FM3            "Value on FM3"
#define TR_GVAR_HEADERS_FM4            "Value on FM4"
#define TR_GVAR_HEADERS_FM5            "Value on FM5"
#define TR_GVAR_HEADERS_FM6            "Value on FM6"
#define TR_GVAR_HEADERS_FM7            "Value on FM7"
#define TR_GVAR_HEADERS_FM8            "Value on FM8"

// Horus footer descriptions
#define TR_LSW_DESCRIPTIONS            { "Comparison type or function", "First variable", "Second variable or constant", "Second variable or constant", "Additional condition for line to be enabled", "Minimum ON duration of the logical switch", "Minimum TRUE duration for the switch to become ON" }

// About screen
#define TR_ABOUTUS                     TR(" ABOUT ", "ABOUT")

#define TR_ABOUT_OPENTX_1              TR("OpenTX\001is\001open\001source,\001non", "OpenTX is open source, non-")
#define TR_ABOUT_OPENTX_2              TR("commercial,\001wo\001warranties.", "commercial and comes with no")
#define TR_ABOUT_OPENTX_3              TR("It\001was\001developed\001for\001free.", "warranties. It was developed")
#define TR_ABOUT_OPENTX_4              TR("Support through donations", "for free. Support through")
#define TR_ABOUT_OPENTX_5              TR("is welcome!", "donations is welcome!")

#define TR_ABOUT_BERTRAND_1            "Bertrand Songis"
#define TR_ABOUT_BERTRAND_2            "OpenTX main author"
#define TR_ABOUT_BERTRAND_3            "Companion co-author"

#define TR_ABOUT_MIKE_1                "Mike Blandford"
#define TR_ABOUT_MIKE_2                "Code and drivers guru"
#define TR_ABOUT_MIKE_3                TR("Arguably,\001one\001of\001the\001best", "Arguably, one of the best")
#define TR_ABOUT_MIKE_4                "Inspirational"

#define TR_ABOUT_ROMOLO_1              "Romolo Manfredini"
#define TR_ABOUT_ROMOLO_2              "Companion co-author"
#define TR_ABOUT_ROMOLO_3              ""

#define TR_ABOUT_ANDRE_1               "Andre Bernet"
#define TR_ABOUT_ANDRE_2               "Functionality, usability,"
#define TR_ABOUT_ANDRE_3               "debugging, documentation"

#define TR_ABOUT_ROB_1                 "Rob Thomson"
#define TR_ABOUT_ROB_2                 "openrcforums webmaster"

#define TR_ABOUT_KJELL_1               "Kjell Kernen"
#define TR_ABOUT_KJELL_2               TR("www.open-tx.org author", "www.open-tx.org main author")
#define TR_ABOUT_KJELL_3               "OpenTX Recorder author"
#define TR_ABOUT_KJELL_4               "Companion contributor"

#define TR_ABOUT_MARTIN_1              "Martin Hotar"
#define TR_ABOUT_MARTIN_2              "Graphics designer"

#if defined(PCBTARANIS) || defined(PCBHORUS)
  #define TR_ABOUT_HARDWARE_1          "FrSky"
  #define TR_ABOUT_HARDWARE_2          TR("Hardware design/producer", "Hardware designer/producer")
  #define TR_ABOUT_HARDWARE_3          "Firmware contributor"
#else
  #define TR_ABOUT_HARDWARE_1          "Brent Nelson"
  #define TR_ABOUT_HARDWARE_2          "Sky9x designer/producer"
  #define TR_ABOUT_HARDWARE_3          ""
#endif

#define TR_ABOUT_PARENTS_1             "Parent projects"
#define TR_ABOUT_PARENTS_2             TR("Ersky9x (Mike Blandford)", "Ersky9x (Mike Blandford)")
#define TR_ABOUT_PARENTS_3             "ER9X (Erez Raviv)"
#define TR_ABOUT_PARENTS_4             "TH9X (Thomas Husterer)"

#define TR_CHR_SHORT                   's'
#define TR_CHR_LONG                    'l'
#define TR_CHR_TOGGLE                  't'
#define TR_CHR_HOUR                    'h'
#define TR_CHR_INPUT                   'I'   // Values between A-I will work

#define TR_BEEP_VOLUME                 "Beep volume"
#define TR_WAV_VOLUME                  "Wav volume"
#define TR_BG_VOLUME                   TR("Bg volume", "Background volume")

#define TR_TOP_BAR                     "Top bar"
#define TR_FLASH_ERASE                 "Flash erase..."
#define TR_FLASH_WRITE                 "Flash write..."
#define TR_OTA_UPDATE                  "OTA update..."
#define TR_MODULE_RESET                "Module reset..."
#define TR_UNKNOWN_RX                  "Unknown RX"
#define TR_UNSUPPORTED_RX              "Unsupported RX"
#define TR_OTA_UPDATE_ERROR            "OTA update error"
#define TR_DEVICE_RESET                "Device reset..."
#define TR_ALTITUDE                    INDENT "Altitude"
#define TR_SCALE                       "Scale"
#define TR_VIEW_CHANNELS               "View Channels"
#define TR_VIEW_NOTES                  "View Notes"
#define TR_MODEL_SELECT                "Model Select"
#define TR_MODS_FORBIDDEN              "Modifications forbidden!"
#define TR_UNLOCKED                    "Unlocked"
#define TR_ID                          "ID"
#define TR_PRECISION                   "Precision"
#define TR_RATIO                       "Ratio"
#define TR_FORMULA                     "Formula"
#define TR_CELLINDEX                   "Cell index"
#define TR_LOGS                        "Logs"
#define TR_OPTIONS                     "Options"
#define TR_FIRMWARE_OPTIONS            "Firmware options"

#define TR_ALTSENSOR                   "Alt sensor"
#define TR_CELLSENSOR                  "Cell sensor"
#define TR_GPSSENSOR                   "GPS sensor"
#define TR_CURRENTSENSOR               "Sensor"
#define TR_AUTOOFFSET                  "Auto Offset"
#define TR_ONLYPOSITIVE                "Positive"
#define TR_FILTER                      "Filter"
#define TR_TELEMETRYFULL               TR("All slots full!", "All telemetry slots full!")
#define TR_SERVOS_OK                   "Servos OK"
#define TR_SERVOS_KO                   "Servos KO"
#define TR_INVERTED_SERIAL             INDENT "Invert"
#define TR_IGNORE_INSTANCE             TR(INDENT "No inst.", INDENT "Ignore instances")
#define TR_DISCOVER_SENSORS            "Discover new sensors"
#define TR_STOP_DISCOVER_SENSORS       "Stop discovery"
#define TR_DELETE_ALL_SENSORS          "Delete all sensors"
#define TR_CONFIRMDELETE               "Really " LCDW_128_480_LINEBREAK "delete all ?"
#define TR_SELECT_WIDGET               "Select widget"
#define TR_REMOVE_WIDGET               "Remove widget"
#define TR_WIDGET_SETTINGS             "Widget settings"
#define TR_REMOVE_SCREEN               "Remove screen"
#define TR_SETUP_WIDGETS               "Setup widgets"
#define TR_USER_INTERFACE              "User interface"
#define TR_THEME                       "Theme"
#define TR_SETUP                       "Setup"
#define TR_MAINVIEWX                   "Main view X"
#define TR_LAYOUT                      "Layout"
#define TR_ADDMAINVIEW                 "Add main view"
#define TR_BACKGROUND_COLOR            "Background color"
#define TR_MAIN_COLOR                  "Main color"
#define TR_TEXT_VIEWER                 "Text Viewer"

#define TR_MENU_INPUTS                 "\314Inputs"
#define TR_MENU_LUA                    "\322Lua scripts"
#define TR_MENU_STICKS                 "\307Sticks"
#define TR_MENU_POTS                   "\310Pots"
#define TR_MENU_MAX                    "\315MAX"
#define TR_MENU_HELI                   "\316Cyclic"
#define TR_MENU_TRIMS                  "\313Trims"
#define TR_MENU_SWITCHES               "\312Switches"
#define TR_MENU_LOGICAL_SWITCHES       "\312Logical switches"
#define TR_MENU_TRAINER                "\317Trainer"
#define TR_MENU_CHANNELS               "\320Channels"
#define TR_MENU_GVARS                  "\311GVars"
#define TR_MENU_TELEMETRY              "\321Telemetry"
#define TR_MENU_DISPLAY                "DISPLAY"
#define TR_MENU_OTHER                  "Other"
#define TR_MENU_INVERT                 "Invert"
#define TR_JITTER_FILTER               "ADC filter"
#define TR_RTC_CHECK                   TR("Check RTC", "Check RTC voltage")
#define TR_AUTH_FAILURE                "Auth-failure"

#define ZSTR_RSSI                      "\022\023\023\011"
#define ZSTR_R9PW                      "\022\044\020\027"
#define ZSTR_RAS                       "\023\027\022"
#define ZSTR_A1                        "\001\034"
#define ZSTR_A2                        "\001\035"
#define ZSTR_A3                        "\001\036"
#define ZSTR_A4                        "\001\037"
#define ZSTR_BATT                      "\022\350\002\354"
#define ZSTR_ALT                       "\001\364\354"
#define ZSTR_TEMP1                     "\024\363\360\034"
#define ZSTR_TEMP2                     "\024\363\360\035"
#define ZSTR_TEMP3                     "\024\363\360\036"
#define ZSTR_TEMP4                     "\024\363\360\037"
#define ZSTR_RPM2                      "\022\020\015\035"
#define ZSTR_PRES                      "\020\356\373\355"
#define ZSTR_ODO1                      "\017\374\361\034"
#define ZSTR_ODO2                      "\017\374\361\035"
#define ZSTR_TXV                       "\024\030_\026"
#define ZSTR_CURR_SERVO1               "\003\023\352\034"
#define ZSTR_CURR_SERVO2               "\003\023\352\035"
#define ZSTR_CURR_SERVO3               "\003\023\352\036"
#define ZSTR_CURR_SERVO4               "\003\023\352\037"
#define ZSTR_DIST                      "\004\367\355\354"
#define ZSTR_ARM                       "\001\356\363"
#define ZSTR_C50                       "\003\040\033"
#define ZSTR_C200                      "\003\035\033\033"
#define ZSTR_RPM                       "\022\020\015"
#define ZSTR_FUEL                      "\006\353\373\364"
#define ZSTR_VSPD                      "\026\023\360\374"
#define ZSTR_ACCX                      "\001\375\375\030"
#define ZSTR_ACCY                      "\001\375\375\031"
#define ZSTR_ACCZ                      "\001\375\375\032"
#define ZSTR_GYROX                     "\007\031\022\030"
#define ZSTR_GYROY                     "\007\031\022\031"
#define ZSTR_GYROZ                     "\007\031\022\032"
#define ZSTR_CURR                      "\003\353\356\356"
#define ZSTR_CAPACITY                  "\003\377\360\377"
#define ZSTR_VFAS                      "\026\006\001\023"
#define ZSTR_ASPD                      "\001\023\360\374"
#define ZSTR_GSPD                      "\007\023\360\374"
#define ZSTR_HDG                       "\010\374\371"
#define ZSTR_SATELLITES                "\023\377\354\355"
#define ZSTR_CELLS                     "\003\373\364\355"
#define ZSTR_GPSALT                    "\007\001\364\354"
#define ZSTR_GPSDATETIME               "\004\377\354\373"
#define ZSTR_GPS                       "\007\020\023"
#define ZSTR_BATT1_VOLTAGE             "\022\002\034\026"
#define ZSTR_BATT2_VOLTAGE             "\022\002\035\026"
#define ZSTR_BATT1_CURRENT             "\022\002\034\001"
#define ZSTR_BATT2_CURRENT             "\022\002\035\001"
#define ZSTR_BATT1_CONSUMPTION         "\022\002\034\003"
#define ZSTR_BATT2_CONSUMPTION         "\022\002\035\003"
#define ZSTR_BATT1_TEMP                "\022\002\034\024"
#define ZSTR_BATT2_TEMP                "\022\002\035\024"
#define ZSTR_RB_STATE                  "\022\002\023"
#define ZSTR_CHANS_STATE               "\022\002\003\023"
#define ZSTR_RX_RSSI1                  "\034\022\023\023"
#define ZSTR_RX_RSSI2                  "\035\022\023\023"
#define ZSTR_RX_QUALITY                "\022\021\364\347"
#define ZSTR_RX_SNR                    "\022\023\016\022"
#define ZSTR_RX_NOISE                  "\022\016\355\373"
#define ZSTR_ANTENNA                   "\001\016\024"
#define ZSTR_RF_MODE                   "\022\006\015\004"
#define ZSTR_TX_POWER                  "\024\020\027\022"
#define ZSTR_TX_RSSI                   "\024\022\023\023"
#define ZSTR_TX_QUALITY                "\024\021\364\347"
#define ZSTR_TX_SNR                    "\024\023\016\022"
#define ZSTR_TX_NOISE                  "\024\016\355\373"
#define ZSTR_PITCH                     "\020\354\375\370"
#define ZSTR_ROLL                      "\022\361\364\364"
#define ZSTR_YAW                       "\031\377\351"
#define ZSTR_FLIGHT_MODE               "\006\015"
#define ZSTR_THROTTLE                  "\024\370\356"
#define ZSTR_QOS_A                     "\006\374\373\001"
#define ZSTR_QOS_B                     "\006\374\373\002"
#define ZSTR_QOS_L                     "\006\374\373\014"
#define ZSTR_QOS_R                     "\006\374\373\022"
#define ZSTR_QOS_F                     "\006\014\355\355"
#define ZSTR_QOS_H                     "\010\361\364\374"
#define ZSTR_BIND                      "\002\011\016\004"
#define ZSTR_LAP_NUMBER                "\014\377\360 "
#define ZSTR_GATE_NUMBER               "\007\377\354\373"
#define ZSTR_LAP_TIME                  "\014\377\360\024"
#define ZSTR_GATE_TIME                 "\007\354\373\024"
#define ZSTR_ESC_VOLTAGE               "\005\355\375\026"
#define ZSTR_ESC_CURRENT               "\005\355\375\001"
#define ZSTR_ESC_RPM                   "\005\355\375\022"
#define ZSTR_ESC_CONSUMPTION           "\005\355\375\003"
#define ZSTR_ESC_TEMP                  "\005\355\375\024"
#define ZSTR_SD1_CHANNEL               "\003\370\377\362"
#define ZSTR_GASSUIT_TEMP1             "\007\024\360\034"
#define ZSTR_GASSUIT_TEMP2             "\007\024\360\035"
#define ZSTR_GASSUIT_RPM               "\007\022\020\015"
#define ZSTR_GASSUIT_FLOW              "\007\006\364\361"
#define ZSTR_GASSUIT_CONS              "\007\006\353\373"
#define ZSTR_GASSUIT_RES_VOL           "\007\022\026\364"
#define ZSTR_GASSUIT_RES_PERC          "\007\022\020\375"
#define ZSTR_GASSUIT_MAX_FLOW          "\007\015\006\364"
#define ZSTR_GASSUIT_AVG_FLOW          "\007\001\006\364"
#define ZSTR_SBEC_VOLTAGE              "\002\373\375\026"
#define ZSTR_SBEC_CURRENT              "\002\373\375\001"
