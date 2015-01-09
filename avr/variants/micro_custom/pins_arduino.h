/*
Copyright (c) 2014 NicoHood
See the readme for credit to other people.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

// include the standard micro board definition file
#include "../micro/pins_arduino.h"

//================================================================================
// HID Settings
//================================================================================

/*
You have two options to enable/disbale hid functions:

The nearly full automatic way which enables the specific hid report for you,
enables the specific hid api and also enables the keyboard led function if needed.

The fully customizable variant where you can create your very own HID report.
You still can use the predefined hid reports or add you very own ones.
You have to enable the specific hid apis on your own then, also the keyboard led function.
*/

#define HID_AUTOMATIC
#define HID_CUSTOM_SETTINGS

//================================================================================
// Automatic
//================================================================================

#ifdef HID_AUTOMATIC
// pre selected hid reports with autoinclude of the api
#define HID_MOUSE_ENABLE // normal mouse with buttons + wheel
//#define HID_MOUSE_ABSOLUTE_ENABLE // only works with system and without gamepad
#define HID_KEYBOARD_LEDS_ENABLE // leds OR keys
//#define HID_KEYBOARD_KEYS_ENABLE
//#define HID_RAWHID_ENABLE // currently not working
//#define HID_CONSUMER_ENABLE
//#define HID_SYSTEM_ENABLE
//#define HID_GAMEPAD_ENABLE // only works without mouse absolute

//================================================================================
// Custom Settings
//================================================================================

#elif defined(HID_CUSTOM_SETTINGS)

// default setting here shows a mouse + keyboard with no led function
// like in IDE 1.0.6/1.5.8 or lower

// use this to enable the Keyboard Led functions
//#define HID_KEYBOARD_LEDS_ENABLED

// add your custom report here:
#define EXTERN_HID_REPORT \
HID_REPORT_KEYBOARD_KEYS(HID_REPORTID_KEYBOARD), \
HID_REPORT_MOUSE(HID_REPORTID_MOUSE)

// activate your custom HID-APIs here:
#define HID_MOUSE_API_ENABLE
#define HID_KEYBOARD_API_ENABLE
//#define HID_RAWHID_API_ENABLE
//#define HID_CONSUMER_API_ENABLE
//#define HID_SYSTEM_API_ENABLE
//#define HID_GAMEPAD_API_ENABLE
//#define HID_ENABLE_ALL_APIS // enables all of the ones above

/*
You can use the pre defined reports as well.
Keep in mind that changing the ids or reports might confuse your OS.
Then you might need to reinstall all drivers or change the USB PID.
Mouse Abs only works with a System report together.
Gamepad and Mouse Abs dont work together.
Gamepads can causes some recognition problems with some OS.
RAW HID seems to not works properly in a multireport.
Currently available pre defined reports :
*/

//HID_REPORT_KEYBOARD_LEDS(HID_REPORTID_KEYBOARD),
//HID_REPORT_KEYBOARD_KEYS(HID_REPORTID_KEYBOARD),
//HID_REPORT_MOUSE(HID_REPORTID_MOUSE),
//HID_REPORT_MOUSE_ABSOLUTE(HID_REPORTID_MOUSE_ABSOLUTE),
//HID_REPORT_RAWHID(HID_REPORTID_RAWHID),
//HID_REPORT_CONSUMERCONTROL(HID_REPORTID_CONSUMERCONTROL),
//HID_REPORT_SYSTEMCONTROL(HID_REPORTID_SYSTEMCONTROL),
//HID_REPORT_GAMEPAD(HID_REPORTID_GAMEPAD),

#else
#error Please select automatic or custom hid report in the pins_arduino.h!
#endif