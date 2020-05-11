# dp v0.7.5 Features
## Main Settings
### Services
**Enable Logger**
```
This will turn on / off logger service, disable this will completed stop logging anything. (e.g. camera footage, canbus logs)
(reboot required)
```
**Enable Uploader**
```
Disable this will stop uploader service upload your logs (camera footage, canbus logs).
If you would like to keep a copy of your logs, you can disable it first > backup > then re-enable this to upload.
(reboot required)
```
**Enable Dashcam**
```
originally from pjlao307 (https://github.com/pjlao307/), this will record whatever showing on the EON screen.
(footages stored in /sdcard/dashcam/)
```

### Hardware
**Enable Hotspot on Boot**
```
This will turn on hotspot (wifi tethering) in your EON automatically when boot up.
```
**Enable Auto Shutdown**
```
This will allow EON to shutdown automatically after it disconnected from usb.
If you have comma power connected, this feature will not work.
```
**Auto Shutdown (min)**
```
Adust the shutdown delay timer. 
```
**Enable Noctua Fan Mode**
```
If you modify EON with Noctua fan (connect to old fan wires), enable this will allow EON to set them running at full speed all time.
```
**Charging Control**
```
Enable this will keep your EON battery between 60% and 70%.
This will not work with comma two. 
```
**Temp Control**
```
Enable this will keep your dp running/controlling and ignoring the device temperature.
```

### Tuning
**Camera Offset (cm)**
```
Adjust this value if your EON is not mounted as per instruction, or, if you find your car lean to one side, change this value should help a bit as well.
* Leaning towards to the left, reduce this value.
* Leaning towards to the right, increase this value.
Default is 6 cm as per system standard.  
```
**Enable Steer Ratio Learner**
```
Enable/Disable steer ratio learner, users reported that it's more stable if you use the stock steer ratio (Disable) value than the steer ratio learner (Enable).
To use stock steer ratio:
1. Disable steer ratio learner.
2. modify "steerRatio" value in /data/params/d/LiveParameters to your car spec.

To revert it back, simply turn the steer ratio learner back on. 
```
### Fingerprint
**Custom Model**
```
This will allow you to quickly select any supported car model without the need of fingerprints.
* WARNING: you may damage your car if you select a unmatched model.
```
**Open Android Settings (Button)**
```
This will give you access to all android settings, click on "Themes" or reboot if you would like to go back to EON screen.
```
**Update Panda Firmware**
```
This button will run flash panda firmware command, once it's done, your EON should reboot automatically.
If you don't see your EON reboot, meaning there is something wrong while flashing, simply disconnect your Panda from power source and restart your EON then try again.
```

## Controls Settings
### Lateral Control
**Enable Lateral Control**
```
If you disable this, it will stop sending lateral control command and only control speed for you (e.g. ACC only). 
```
**Display "Turn Exceeds Steering" Limit" Alert**
```
Cars like Honda has limited steering angle/torque, when the curvature is higher than the limitation, dragonpilot sends alerts to warn the driver,
Disable this will stop any of those alerts.
```
**Enable Steering On Signal**
```
Turn this on if you want to temporary disable dragonpilot's lateral control when blinker/singal is on.
* You will see this option only when stock "Enable Lane Change Assist" is disabled.
```
**Enable Auto Lane Change**
```
If your speed reach 60mph / 97kph or above and has left or right blinker on, it will help you to change lane with a 3 seconds delay.
You can override the 3 seconds delay by applying force on the steering wheel.
NOTE: if you do not turn off your blinker, it will keep changing to the next lane (3 seconds delay applied).   
* You will see this option only when stock "Enable Lane Change Assist" is enabled.
```

### Longitudinal Control
**Following Distance Profile**
```
This option allows you to adjust the distance between your car and lead car.
When it's not set to "OFF", you can quickly adjust the mode on driving ui. 

Special thanks to @ShaneSmiskol for providing this feature.
Choice of: "OFF", "LONG", "NORMAL", "SHORT"
```
**Acceleration Profile**
```
This option allows you to adjust the acceleration/de-acceleration of dragonpilot.
When it's not set to "OFF", you can quickly adjust the mode on driving ui.

Special thanks to @arne182 for providing this feature.
Choice of: "OFF", "ECO", "NORMAL", "SPORT"
```
**Allow Gas**
```
Enable this will allow you to use gas pedal while dragonpilot is engaged.
```
**Enable Slow on Curve**
```
Disable this if you do not wish to slow down on curve automatically.
```
**Enable Lead Car Moving Alert**
```
dragonpilot will send an alert when:
a lead car stopped in front of you for more than 3s then started moving
```

### Safety Monitors
**Enable Driver Monitoring**
```
Driver monitoring is permenantly enabled since 0.6.4 and this option will let you enable/disable driver monitoring.
* You will see this option only when "Enable Safety Check" is enabled.
```
**Steering Monitor Timer**
```
This option allows you to adjust the timer for steering monitor, set it to OFF if you do not wish to monitor through steering wheel.
* You will see this option only when "Enable Safety Check" is enabled.
```
**Enable Gear Safety Check**
```
This feature will disable gear safety check, this is useful when driving a manual car.
```

## UI Settings
**Display Driving UI**
```
Disable this will hide camera footage from the screen and leaves you only the sidebar and the rest of the UI components (that can be enable/disable below).
It's good for using with TomTom or any other android apps run in full screen mode.
```
**Turn Off Screen When Reversing**
```
Enable this will temporary turn off device screen when the car is reversing, special thanks to @mlp for providing this feature.  
```

**Display Driver Monitor View**
```
This allows you to see the driver monitor view on your screen, handy if you want to know why Driver Monitor does not work for you sometimes.
```
**Display Speed**
**Display Lane Prediction**
**Display Path Prediction**
**Display Turning Signal**
**Display Event / Steering Icon**
**Display Max Speed**
**Display Face Icon**
**Display Dev UI**
```
This allows you to see steer/speed values from model/car, similar to kegman/arne display.
```
**Display Mini Dev UI**
```
This allows you to see steer/speed values from model/car in dragonpilot way.
```
**Boost Audio Alert Volume (%)**
```
This allow you to adjust the warning alert sounds, the system adjust volume based on the speed of the car, this option can increase/decrease the volume on top of that.
* range: -100 to 100. (in %)
```

# 3rd Party Apps Settings
**Use External GPS Signal**
```
Enable this will pass grey/black/C2 GPS signal to navigation apps.
* You may see 桃園區 displayed on Home screen.
* You may need to restart your device to take effect.
```
**Enable Waza Mode**
```
Enable this will turn your EON into a Waze Navigator,  once it's enabled:
1. It will disable Tomtom/Autonavi/Aegis apps.
2. It will disable most of the driving UI elements. (you still see all the warnings.)
3. Once the car is started, Waze will start automatically.
4. Once Waze is started, you cannot make any changes to the DP settings*.
   (* We need to disable frame app to enable soft keyboard.)

The app will download from github the moment you enable this feature so please make sure you have internet connected.
```
**Enable TomTom Safety Camera App**
```
Enable this will allow you to use TomTom Safety Camera App.

The app will download from github the moment you enable this feature so please make sure you have internet connected.
```
**Auto Run TomTom Safety Camera App**
```
Enable this will allow TomTom Safety Camera to run automatically when the car started.
 ```
**Enable Autonavi Map App**
```
Enable this will allow you to use Autonavi Map (高德地圖車機版) App.
* This is for Mainland China users.

The app will download from github the moment you enable this feature so please make sure you have internet connected.
 ```
**Auto Run Autonavi Map App**
```
Enable this will allow Autonavi Map to run automatically when the car started.
 ```
**Enable Aegis Safety Camera App**
```
Enable this will allow you to use Aegis Safety Camera (神盾測速照相) App.
* This is for Taiwan users.

The app will download from github the moment you enable this feature so please make sure you have internet connected.
 ```
**Auto Run Aegis Safety Camera App**
```
Enable this will allow Aegis Safety Camera to run automatically when the car started.
 ```
**Enable MiXplorer App**
```
Enable this will allow you to use MiXplorer (File manager) App.

The app will download from github the moment you enable this feature so please make sure you have internet connected.
 ```

# Brand Specific Settings
### Toyota / Lexus
**~~Enable Stock DSU Mode~~**
```
Due to comma's safety guideline, this feature is no longer fully working beyond 0.7.4 
This is for TSS-P cars w/ DSU connected, once this is enabled, dragonpilot will be engaged when main ACC switch is on, disengaged when main ACC switch is off.
dragonpilot will stay engaged all time for lateral control and wont be disengaged if step on gas or brake.
```
**Enable Lane Departure Warning**
```
Disable this will stop reciving Lane Departure warning (alerts/steering wheel vibration).
```
**Enable SnG Mod**
```
Enable this will apply stop n go hack, see https://github.com/commaai/openpilot/pull/741 for more information.
```

# Advanced Settings (SSH/SFTP Required)
dp has a few additional settings that can only be modified via SSH/command line (limit to advanced users only), to modify value:
```
printf %s "1" > /data/params/d/ParamName
``` 
**DragonAssistedLCMinMPH**
```
This allows you to adjust the minimum speed (in MPH) to trigger assisted lane change.

* Default value: 37 (MPH)
* Accept value: any float value greater than 0.
* 0 will be used if set below 0.
* If this value is larger than DragonAutoLCMinMPH, it will set to the same value as DragonAutoLCMinMPH.

printf %s "37" > /data/params/d/DragonAssistedLCMinMPH    
```
**DragonAutoLCMinMPH**
```
This allows you to adjust the minimum speed (in MPH) to trigger auto lane change.

* Default value: 60 (MPH)
* Accept value: any float value greater than 0.
* 0 will be used if set below 0.

printf %s "60" > /data/params/d/DragonAutoLCMinMPH
```
**DragonAutoLCDelay**
```
This allows you to adjust the delay to trigger auto lane change.

* Default value: 2 (seconds)
* Accept value: any float value greater than 0.
* 0 will be used if set below 0.

printf %s "2" > /data/params/d/DragonAutoLCDelay
```
**DragonBTG**
```
Due to incompetible CAN message issue, some of the users (Taiwan Toyota RAV4 + Car Harness) were not be able to use
Car Harness properly.

to enable this mod:
cd /data/openpilot && chmod +x btg_mode.sh && ./btg_mode.sh 1

to disable this mod:
cd /data/openpilot && chmod +x btg_mode.sh && ./btg_mode.sh 0
```
**DragonCharging**
```
This allows you to adjust the battery charging percentage, when your battery reach the value, it will stop charging.

* You will need to turn on "Charging Control" option.
* Default value: 70 (%)
* Accept value: 0 to 100.

printf %s "80" > /data/params/d/DragonCharging
```
**DragonDisCharging**
```
This allows you to adjust the battery discharging percentage, when your battery reach the value, it will start charging.

* You will need to turn on "Charging Control" option.
* Default value: 60 (%)
* Accept value: 0 to 100.

printf %s "70" > /data/params/d/DragonDisCharging
```
**DragonToyotaSngResponse**
```
This allows you to adjust the stop and go response when the fornt car starts moving on Toyota/Lexsus cars.

* Your Toyota/Lexsus vehicle must have one of following condition: TSS-P with Smart DSU, DSU unplugged, or TSS2 feature.
* Your Comma Two or Eon must have Community Feature enabled.
* Default value: 0.0
* Accept value: any float value greater than 0.0
* Reboot required

printf %s "7.0" > /data/params/d/DragonToyotaSngResponse
```

there are a few undocumented settings can be found in /data/openpilot/selfdrive/dragonpilot/dragonconfig/__init__.py, try at your own risk :)
