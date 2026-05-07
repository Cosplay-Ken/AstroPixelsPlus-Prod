# FORK Information

## Reson:
I could not find a reliable, stable, non blocking way to have the DroidLInk Dome maestro automate random holoprojector movements and moods without interfeering with existing panel sequences and scripts. 

## Scope: 
To have a non blocking way to automate, custominze, and control the random behivior of the holoprojectors to free up scripting and sequences from the dome panel Maestro of DroidLink. Aslo to be able to inturupt the automation when specific movements are required, then resume after complete.

## Results:
Holoprojector movement, control, and automation has been offloaded from maestro to AstropixlesPlus. These movements can be inturupted if specific movemends are sent with other serial commands (such as stopping front holoprojector movement during the Leia playback message)

## Control:
main control is by sending serial commands from the DroidLink Display for controlling moods (calm, Normal, excited, Save). The R2 Touch app still works as it always has and buttons within it can be pregrammed with the same serial commands, although I do not use the R2 Touch app (maybe sometimes during testing). Further cusrtomazation can be access in the AstroPixelsPlus web interface. A new 'Holoprojector' panel has been added where additional customazation can be made. 

## Instrucrions:

This is a modification of the AstroPixlesPlus firmware that better incorporates with the DroidLink astromech control system developed by Fred Moore. DroidLink is best used with Polulu Maestro servo boards but does not script the automated holoprojector movements very well. This update keeps the Holoprojectors attached to AstroPixelsPlus and adds automation and customazation to randomely move the 3 holoprojectors and toggle to three preset modes. It offers 4 new serail commands to add to DroidLink Display to trigger these moods with the press of a button. Additional customazation can be performed in the AstopPixels Plus GUI by adjusting settings sliders to meet your particular needs. The setting take affect immediately and can also be saved, so the settings return after a reboot.  

All functionality of the origional AstroPixelsPlus firmware have been retained but some changes were made to align with using DroidLink.  The following prequestie is required for this configuration.

Servo Board layout has changed. Board 1 (position 1-6) are now assigned to the holoprojectr servos. Board 2 (position 1-13) are assigned to panels. If using droidLink board 2 is no longer required since panel movement will be controled by the maestro board. 

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


The other improvement (and the main reason for doing this project) is automated holoprojector movements with cusomeazation. I set up Astropixles to randomly move the 3 holoprojectors automatically upon system bootup.  Three moods are preset that can be activated by sending serial commands from the DroidLink Display.

Calm - *HLC1  
Normal - *HLN1  
Excited - *HLE1  
Save - *HLSV1  

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

 
The decritptions of the setting is as follows.

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

### Ide Time
Pause between bursts. This is how long the system “does nothing” before starting another burst.
1000–3000 ms → very active, almost constantly moving
3000–8000 ms → balanced, natural idle behavior (good default)
8000–20000 ms → slow, observant, cinematic R2-style pauses

### Web Installer: 
https://cosplay-ken.github.io/AstroPixelsPlus-Prod/
 
### Origional AstroPixlesPlus Documentation
https://github.com/reeltwo/AstroPixelsPlus
