# FORK Information

## Reson:
This fork was created to provide a reliable, stable, and fully non-blocking solution for automated holoprojector movement within the DroidLink ecosystem.  

The original DroidLink + Maestro setup works extremely well for dome panels and sequencing, but automated holoprojector behavior could interfere with running panel scripts and other timed actions. This project moves holoprojector automation away from the Maestro and into AstroPixelsPlus, allowing both systems to operate independently without conflicts.

## Scope: 
The goal of this project is to:

* Provide fully non-blocking automated holoprojector movement
* Allow customizable random holoprojector behavior
* Free DroidLink panel scripting from holoprojector management
* Allow automated movements to be interrupted for scripted actions
* Automatically resume idle behavior after scripted movements complete

## Results:
Holoprojector movement and automation have been fully offloaded from the Maestro to AstroPixelsPlus.

This allows:

* Independent automated holoprojector behavior
* Cleaner DroidLink panel scripting
* Real-time mood changes
* Interruptible movements for special sequences

Example: during a Leia playback sequence, the front holoprojector can stop moving while audio or scripted events occur, then automatically resume idle behavior afterward.

## Control:
Primary control is handled through serial commands sent from the DroidLink Display system to control holoprojector moods:

* Calm
* Normal
* Excited
* Save Current Settings

The R2 Touch app continues to function normally and can also trigger these same commands if desired.

Additional customization is available directly through the AstroPixelsPlus web interface. A new Holoprojector configuration panel has been added for live tuning and adjustment.
## Instrucrions:

This is a modified version of the AstroPixelsPlus firmware designed specifically to integrate more cleanly with the DroidLink astromech control system developed by Fred Moore.

DroidLink works exceptionally well with Pololu Maestro Servo Controllers
 for dome panel control, but automated holoprojector movement was difficult to manage cleanly through Maestro scripting alone.

This fork keeps the holoprojectors connected to AstroPixelsPlus while adding:

* Automated random holoprojector movement
* Multiple movement “moods”
* Real-time customization
* Non-blocking behavior
* Script interruption handling
* Web-based tuning controls

All original AstroPixelsPlus functionality has been retained, although some configuration changes were made to better align with DroidLink usage.

The servo board layout has changed for this configuration.

<table align="center">
<tr>
<td valign="top" align="left">

### Board 1
- Position 1 - Front Holo Horizontal
- Position 2 - Front Holo Vertical
- Position 3 - Top Holo Horizontal
- Position 4 - Top Holo Vertical
- Position 5 - Rear Holo Horizontal
- Position 6 - Rear Holo Vertical

</td>

<td valign="top" align="left">

### Board 2 (Optional)
- Position 1 - Panel 4
- Position 2 - Panel 3
- Position 3 - Panel 2
- Position 4 - Panel 1
- Position 5 - Panel 5
- Position 6 - Panel 9
- Position 7 - Mini Panel 2
- Position 8 - Mini Front PSI Panel
- Position 9 - Pie Panel 1
- Position 10 - Pie Panel 2
- Position 11 - Pie Panel 3
- Position 12 - Pie Panel 4
- Position 13 - Top Dome Panel

</td>
</tr>
</table>

Automated Holoprojector Movement

The primary feature of this project is automated holoprojector movement with live customization.

AstroPixelsPlus automatically begins random holoprojector movement during startup. Three preset “moods” can be triggered at any time using serial commands from DroidLink Display.



Web Interface

A new Holoprojector page has been added to the AstroPixelsPlus web interface.

From this screen you can adjust:

Burst Size
Burst Speed
Idle Time

Changes update live in real time and can usually be observed within a few seconds.

Settings can also be saved so they persist after reboot. If settings are not saved, the system defaults back to Normal mode during startup.

Important
Slider adjustments update immediately in real time
Preset buttons and serial commands also update the active settings
After changing modes via serial command or preset button, press Refresh Sliders to update the displayed values in the GUI





The other improvement (and the main reason for doing this project) is automated holoprojector movements with cusomeazation. I set up Astropixles to randomly move the 3 holoprojectors automatically upon system bootup.  Three moods are preset that can be activated by sending serial commands from the DroidLink Display.

Calm - *HLC1  
Normal - *HLN1  
Excited - *HLE1  
Save - *HLSV  

Further cusrtomazation can be found in the AstroPixlesPlus web interface. A new 'Holoprojector' screen has been added on the main screen. From here you can adjust the minimum and maximum values for Burst behivior, burst speed, and idle time. Adjusting these settings will update live and can be noticed within a  few seconds of activation. There is a save button that can save the current values so the next time the system restarts it will start up at what it was saved at, otherwise it reverts to 'Normal" mode. 

If you adjust the settings via the sliders they update in real time. If you adjust the moods via serial commands, or pressing the preset buttons, you have to push 'Refresh Sliders' in order to see the current values. 

<div align="center">
  <table>
    <tr>
      <!-- First Image -->
    <td><img width="288" height="624" alt="Screenshot_20260507-082505" src="https://github.com/user-attachments/assets/442c121d-7e9d-4796-ade8-8c625ccf3b91" /></td>
       <td width="80"></td>
     <!-- Second Image -->
    <td><img width="288" height="624" alt="Screenshot_20260507-082519" src="https://github.com/user-attachments/assets/1f497b4d-5bc4-439d-bda0-0b8f9344ee8e" /></td>
    </tr>
  </table>
</div>

 
### Slider Description

### Burst Size
How many movements happen in a row. This controls how many quick actions happen before the system pauses.
1–2 → very calm, sparse motion (sleepy droid)
1–4 → natural idle behavior (good default)
3–6 → active / alert / “thinking a lot”

### Burst Speed
How fast actions happen. This is the delay between movements inside a burst.
200–400 ms → twitchy / nervous / reactive
400–900 ms → natural mechanical motion (recommended)
900–1500 ms → slow, heavy, deliberate movement

### Idle Time
Pause between bursts. This is how long the system “does nothing” before starting another burst.
1000–3000 ms → very active, almost constantly moving
3000–8000 ms → balanced, natural idle behavior (good default)
8000–20000 ms → slow, observant, cinematic R2-style pauses

## Web Installer: 
https://cosplay-ken.github.io/AstroPixelsPlus-Prod/
 
## Origional AstroPixlesPlus Documentation
https://github.com/reeltwo/AstroPixelsPlus
