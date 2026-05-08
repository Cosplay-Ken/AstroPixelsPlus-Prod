# FORK Information

## Reason:
This fork was created to provide a reliable, stable, and fully non-blocking solution for automated holoprojector movement when paired with the DroidLink ecosystem created by Fred Moore.  

DroidLink + Maestro setup works extremely well for dome panels and sequencing, but automated holoprojector behavior could interfere with running panel scripts and other timed actions. This project moves holoprojector automation away from the Maestro and into AstroPixelsPlus, allowing both systems to operate independently without conflicts.

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
* Non-blocking behavior
* Web-based tuning controls

Example: during a Leia playback sequence, the front holoprojector can stop moving while audio or scripted events occur, then automatically resume idle behavior afterward.

## Control:
Primary control is handled through serial commands sent from the DroidLink Display system to control holoprojector moods:

* On/Off
* Calm
* Normal
* Excited
* Save Current Settings

The R2 Touch app continues to function normally and can also trigger these same commands if desired.

Additional customization is available directly through the AstroPixelsPlus web interface. A new Holoprojector configuration panel has been added for live tuning and adjustment.

## Instructions:

All original AstroPixelsPlus functionality has been retained, although some configuration changes were made to better align with DroidLink usage.

The servo board layout has changed for this configuration. You can still use both boards if you want to control panels but the main idea behind this change is to use Maestro for panels and AstroPixelsPlus for holo movement only. 

<table align="center">
<tr>
<td valign="top" align="left">

### Board 1 (Required)
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

## Web Interface
A new Holoprojector page has been added to the AstroPixelsPlus web interface.

From this screen you can adjust:

* Burst Size
* Burst Speed
* Idle Time
* Presets

Changes update live in real time and can usually be observed within a few seconds.

Settings can also be saved so they persist after reboot. If settings are not saved, the system defaults back to Normal mode during startup.

Important
* Slider adjustments update immediately in real time
* Preset buttons and serial commands also update the active settings
* After changing modes via serial command or preset button, press Refresh Sliders to update the displayed values in the GUI  
  
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
 
## Slider Description

### Burst Size
How many movements happen in a row. This controls how many quick actions happen before the system pauses.  
* 1–2 → very calm, sparse motion (sleepy droid)  
* 1–4 → natural idle behavior (good default)  
* 3–6 → active / alert / “thinking a lot”

### Burst Speed
How fast actions happen. This is the delay between movements inside a burst.    
* 200–400 ms → twitchy / nervous / reactive  
* 400–900 ms → natural mechanical motion (recommended)  
* 900–1500 ms → slow, heavy, deliberate movement

### Idle Time
Pause between bursts. This is how long the system “does nothing” before starting another burst.  
* 1000–3000 ms → very active, almost constantly moving
* 3000–8000 ms → balanced, natural idle behavior (good default)  
* 8000–20000 ms → slow, observant, cinematic R2-style pauses  

## Serial Commands
These are the serial commands that can be sent from the DroidLink Display to turn on/off the automation, change mood, and save configuration. 

* Calm - *HLC1  
* Normal - *HLN1  
* Excited - *HLE1  
* Save - *HLSV 
* Automation On - *HLON
* Automation Off - *HLOFF

## Acknowledgements
When a serial command is processed, or a preset button is used in the web portal, a short acknowledgement signal is emitted from Holoprojector 1.

* Calm — Blue
* Normal — Green
* Excited — Red
* Saved — Flashing White

## Web Installer: 
https://cosplay-ken.github.io/AstroPixelsPlus-Prod/
 
## Origional AstroPixlesPlus Documentation
https://github.com/reeltwo/AstroPixelsPlus
