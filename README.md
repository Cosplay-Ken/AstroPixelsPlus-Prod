# FORK Information

This is a modification of the AstroPixlesPlus firmware that better incorporates with the DroidLink astromech control system developed by Fred Moore.

All functionality of the origional AstroPixelsPlus firmware have been retained but some changes were made to align with using DroidLink.  The following items have been changed or added.

 Servo Board layout has changed. Board 1 (position 1-6) are now assigned to the holoprojectr servos. Board 2 (position 1-13) are assigned to panels.

 
Board 1

Position 1 Front Holo Horizontal
Position 2 Front Holo Vertical
Position 3 Top Holo Horizontal
         Position 4 Top Holo Vertical
         Position 5 Rear Holo Vertical
         Position 6 Rear Holo Horizontal

*     Board 2
*         Position 1 Panel 4
*         Position 2 Panel 3
*         Position 3 Panel 2
*         Position 4 Panel 1


    // First PCA9685 controller
    {1, 800, 2200, PANEL_GROUP_4 | SMALL_PANEL},  /* 0: door 4 */
    {2, 800, 2200, PANEL_GROUP_3 | SMALL_PANEL},  /* 1: door 3 */
    {3, 800, 2200, PANEL_GROUP_2 | SMALL_PANEL},  /* 2: door 2 */
    {4, 800, 2200, PANEL_GROUP_1 | SMALL_PANEL},  /* 3: door 1 */
    {5, 800, 2200, PANEL_GROUP_5 | MEDIUM_PANEL}, /* 4: door 5 */
    {6, 800, 2200, PANEL_GROUP_6 | BIG_PANEL},    /* 5: door 9 */
    {7, 800, 2200, MINI_PANEL},                   /* 6: mini door 2 */
    {8, 800, 2200, MINI_PANEL},                   /* 7: mini front psi door */
    {9, 800, 2200, PANEL_GROUP_10 | PIE_PANEL},   /* 8: pie panel 1 */
    {10, 800, 2200, PANEL_GROUP_9 | PIE_PANEL},   /* 9: pie panel 2 */
    {11, 800, 2200, PANEL_GROUP_8 | PIE_PANEL},   /* 10: pie panel 3 */
    {12, 800, 2200, PANEL_GROUP_7 | PIE_PANEL},   /* 11: pie panel 4 */
    {13, 800, 2200, TOP_PIE_PANEL},               /* 12: dome top panel */

    // Second PCA9685 controller
    {16, 800, 2200, HOLO_HSERVO}, /* 13: horizontal front holo */
    {17, 800, 2200, HOLO_VSERVO}, /* 14: vertical front holo */
    {18, 800, 2200, HOLO_HSERVO}, /* 15: horizontal top holo */
    {19, 800, 2200, HOLO_VSERVO}, /* 16: vertical top holo */
    {20, 800, 2200, HOLO_VSERVO}, /* 17: vertical rear holo */
    {21, 800, 2200, HOLO_HSERVO}, /* 18: horizontal rear holo */





unsigned long lastMoveTime = 0;
unsigned long nextInterval = 0;
int burstCount = 0;

// Burst behavior

// Burst size (how many movements happen in a row)
// This controls how many quick actions happen before the system pauses.
// 1–2 → very calm, sparse motion (sleepy droid)
// 1–4 → natural idle behavior (good default)
// 3–6 → active / alert / “thinking a lot”
int burstMin = 1;
int burstMax = 4;

// Burst speed (how fast those actions happen)
// This is the delay between movements inside a burst.
// 200–400 ms → twitchy / nervous / reactive
// 400–900 ms → natural mechanical motion (recommended)
// 900–1500 ms → slow, heavy, deliberate movement
int burstSpeedMin = 300;
int burstSpeedMax = 800;

// Idle timing (pause between bursts)
// This is how long the system “does nothing” before starting another burst.
// 1000–3000 ms → very active, almost constantly moving
// 3000–8000 ms → balanced, natural idle behavior (good default)
// 8000–20000 ms → slow, observant, cinematic R2-style pauses
int idleMin = 3000;
int idleMax = 8000;





# AstroPixelsPlus Firmware
Alternative firmware sketch for the AstroPixels boards

![AstroPixels](https://we-make-things.co.uk/wp-content/uploads/2022/10/PXL_20220423_103855938-scaled.jpg)

You can order AstroPixels boards here:

https://we-make-things.co.uk/product/astropixels/

# Web Based Installer

Install pre-built firmware directly onto your ESP board using this web based installer.
https://reeltwo.github.io/AstroPixels-Installer/

*Requires Chrome or Edge.*

Check out the Wiki for this firmware:

https://github.com/reeltwo/AstroPixelsPlus/wiki

**********

# Playground

[![Logic Engine](https://thumbs.wokwi.com/projects/347975094870475347/thumbnail.jpg?tile&amp;t=1629669534812&amp;dark=1)](https://wokwi.com/projects/347975094870475347)

# REQUIREMENTS

Arduino IDE: https://www.arduino.cc/en/Main/Software  (1.8.13 or higher)
NeoPixels: https://github.com/adafruit/Adafruit_NeoPixel/releases (1.10.5 or higher)
Reeltwo: https://github.com/reeltwo/Reeltwo/releases  (1.1 or higher)

**********

The default WiFi credentials are:

SSID: AstroPixels  
Password: Astromech 

You can and should change this using the web interface. The default web address of the firmware is http://192.168.4.1

The Serial2 TTL header is by default a Marcduino serial command receiver running at 9600 baud. It will forward any serial data to Serial2 at 9600 baud. Allowing you to daisy chain the AstroPixels board with other Marcdunio compatible serial devices.

**********

# Configuration Commands Supported

## #APWIFI[0|1] - Change WiFi Setting
  #APWIFI - Toggle WiFi
  #APWIFI0 - WiFi Off
  #APWIFI1 - WiFi On

## #APREMOTE[0|1] - Change Droid Remote Setting
  #APREMOTE - Toggle Droid Remote Support
  #APREMOTE0 - Droid Remote Support Off
  #APREMOTE1 - Droid Remote Support On

## #APZERO - Clear All Preference including WiFi Settings

## #APRESTART - Restart AstroPixels

# Marcduino Commands Supported

The prefix @ is optional and is ignored. All Marcduino commands are terminated by \r (carriage return).

## @1T1 - Front Logics set to Normal

## @1T2 - Front Logics set to Flashing Color (06)

## @1T3 - Front Logics set to Alarm (01)

## @1T4 - Front Logics set to Failure (02)

## @1T5 - Front Logics set to Red Alert (11)

## @1T6 - Front Logics set to Leia (03)

## @1T11 - Front Logics set to March (04)

## @2T1 - Rear Logics set to Normal

## @2T2 - Rear Logics set to Flashing Color (06)

## @2T3 - Rear Logics set to Alarm (01)

## @2T4 - Rear Logics set to Failure (02)

## @2T5 - Rear Logics set to Red Alert (11)

## @2T6 - Rear Logics set to Leia (03)

## @2T11 - Rear Logics set to March (04)

## @0T1 - All Logics set to Normal

## @0T2 - All Logics set to Flashing Color (06)

## @0T3 - All Logics set to Alarm (01)

## @0T4 - All Logics set to Failure (02)

## @0T5 - All Logics set to Red Alert (11)

## @0T6 - All Logics set to Leia (03)

## @0T11 - All Logics set to March (04)

## @1MHello - Set top front logics text to "Hello" and scroll left

## @2MWorld - Set bottom front logics text to "World" and scroll left

## @3MAstromech - Set rear logics text to "Astromech" and scroll left

## @1P60 - Set front logics font to Latin

## @2P60 - Set front logics font to Latin

## @3P60 - Set rear logics font to Latin

## @1P61 - Set front logics font to Aurabesh

## @2P61 - Set front logics font to Aurabesh

## @3P61 - Set rear logics font to Aurabesh

# Panel commands

## :CL00 - Close all panels

## :OP00 - Open all panels

## :OF00 - Flutter all panels

## :SF<servo number>$<easing number> - Set servo easing for <servo number> to <easing number>

## :OP<number> - Open panel <number>. For example :OP01

## :CL<number> - Open panel <number> For example: CL02

## :OF<number> - Flutter panel <number> For example: OF02

# Holo projector commands

## *ON01 - Front holo on

## *OF01 - Front holo off

## *ON02 - Rear holo on

## *OF02 - Rear holo off

## *ON03 - Top holo on

## *OF03 - Top holo off

## *ST00 - Reset all holos

## *RD01 - Front holo random move

## *RD02 - Rear holo random move

## *RD03 - Top holo random move

## *HPS301 - Front holo pulse

## *HPS302 - Rear holo pulse

## *HPS303 - Top holo pulse

## *HPS601 - Front holo rainbow

## *HPS602 - Rear holo rainbow

## *HPS603 - Top holo rainbow

## *HP001 - Front holo position down

## *HP101 - Front holo position center

## *HP201 - Front holo position up

## *HP301 - Front holo position left

## *HP401 - Front holo position upper left

## *HP501 - Front holo position lower left

## *HP601 - Front holo position right

## *HP701 - Front holo position upper right

## *HP801 - Front holo position upper right

## *HP002 - Rear holo position down

## *HP102 - Rear holo position center

## *HP202 - Rear holo position up

## *HP302 - Rear holo position left

## *HP402 - Rear holo position upper left

## *HP502 - Rear holo position lower left

## *HP602 - Rear holo position right

## *HP702 - Rear holo position upper right

## *HP802 - Rear holo position upper right

## *HP003 - Top holo position down

## *HP103 - Top holo position center

## *HP203 - Top holo position up

## *HP303 - Top holo position left

## *HP403 - Top holo position upper left

## *HP503 - Top holo position lower left

## *HP603 - Top holo position right

## *HP703 - Top holo position upper right

## *HP803 - Top holo position upper right

## *HN01 - Front holo nod

## *HN02 - Rear holo nod

## *HN03 - Top holo nod

# AstroPixels specific Marcduino commands

Additional you can select a sequence to run by sending:

@APLE followed by a integer in this format LEECSNN

## L - the logic designator - if not provided, defaults to 0 (all)
   0 - All  
   1 - Front  
   2 - Rear  

## EE - the effect - use two digits if logic designator provided
   00 - Reset to Normal  
   01 - Alarm - flips between color and red  
   02 - Failure - cycles colors and brightness fading  
   03 - Leia - pale green  
   04 - March - sequence timed to Imperial March  
   05 - Single Color - single hue shown  
   06 - Flashing Color - single hue on and off  
   07 - Flip Flop Color - boards flip back and forth - similar to march  
   08 - Flip Flop Alt - other direction of flips on back board, front is same to flip flop  
   09 - Color Swap - switches between color specified and inverse compliment color  
   10 - Rainbow - rotates through colors over time  
   11 - Red Alert - shows color specified  
   12 - Mic Bright - brightness of color specified back on mic input  
   13 - Mic Rainbow - color goes from default specified through color range  
   14 - Ligts out - slowly turn off all LEDs  
   15 - Display Text  
   16 - Text Scrolling Left  
   17 - Text Scrolling Right  
   18 - Text Scrolling Up  
   19 - Roaming pixel  
   21 - Vertial scan line  
   22 - Fire  
   23 - PSI style color wipe between two colors  
   99 - Random  
## C - color designator
   1 - Red  
   2 - Orange  
   3 - Yellow  
   4 - Green  
   5 - Cyan (Aqua)  
   6 - Blue  
   7 - Purple  
   8 - Magenta  
   9 - Pink  
   0 - Default color on alarm / default to red on many effects / color cycle on march / ignored on failure and rainbow  
## S - speed or sensitivity (1-9 scale) with 5 generally considered default for speed
   Flip Flop and Rainbow - 200ms x speed  
   Flash - 250ms x speed  
   March - 150ms x speed  
   Color Swap - 350ms x speed  
   Red Alert - sets mic sensitivity - as a fraction of speed / 10 - we recommend 3  
   Mic Bright - sets minimum brightness - fraction of speed / 10  
## NN - 2 digit time length in seconds
   00 for continuous use on most  
   00 for default length on Leia  
   Not used on March or Failure  

 ## Some sequence examples:
 Note: Leading 0s drop off as these are long ints  
 Solid Red:  @APLE51000  
 Solid Orange: @APLE52000  
 Solid Yellow:  @APLE53000  
 Solid Green:  @APLE54000  
 Solid Cyan:  @APLE55000  
 Solid Blue:  @APLE56000  
 Solid Purple:  @APLE57000  
 Solid Magenta:  @APLE58000  
 Solid Pink: @APLE59000  
 Alarm (default):  @APLE10500  
 Failure: @APLE20000  
 Leia: @APLE30000  
 March:  @APLE40500  
 March (Red Only):  @APLE41500  
 Flash (Yellow): @APLE63500  
 Color Swap (pink): @APLE99500  
 Rainbow: @APLE100500  
 Red Alert: @APLE111300  
 Mic Bright (Green): @APLE124200  
 Mic Rainbow (Cyan): @APLE135000  
 Fire: @APLE225000

 @APLE54008 - solid green for 8 seconds  
 @APLE63315 - flashing yellow at slightly higher speed for 15 seconds  
 @APLE30008 - leia effect for only 8 seconds  

**********

## Libraries Used

<ul>
<li>https://github.com/reeltwo/Reeltwo</li>
<li>https://github.com/adafruit/Adafruit_NeoPixel</li>
<li>https://github.com/FastLED/FastLED</li>
<li>https://github.com/DFRobot/DFRobotDFPlayerMini</li>
</ul>
