MAIN
-
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
originally from pjlao307, this will record whatever showing on the EON screen.
(footages stored in /sdcard/dashcam/)
```

**Auto Shutdown (min)**
```
This will allow EON to shutdown automatically after it disconnected from usb.
If you set this to 0, it will disable this feature.
If you have comma power connected, this may not work.
```

**Enable Noctua Fan Mode**
```
If you modify EON with Noctua fan (connect to old fan wires), enable this will allow EON to set them running at full speed full time.
```

**Cache Fingerprint**
```
Enable this will store your fingerprint/model/vin in files so next time when you start the car, it will slightly reduce the time to recognize your car. 
```

**Camera Offset (cm)**
```
Adjust this value if your EON is not mounted as per instruction, or, if you find your car lean to one side, change this value should help a bit as well.
Leaning towards to the left, reduce this value.
Leaning towards to the right, increase this value.
Default is 6 cm as per system standard.  
```

**Open Android Settings Btn**
```
This will give you access to all android setting page, click on "Themes" or reboot if you would like to go back to EON screen.
```

**Update Panda Firmware**
```
This button will run flash panda firmware command, once it's done, your EON should reboot automatically.
If you don't see your EON reboot, meaning there is something wrong while flashing, simply disconnect your Panda from power source and restart your EON then try again.
```

Safety Settings
-
**Enable Lateral Control**
```
If you disable this, it will stop sending lateral control command and only control speed for you (e.g. ACC only). 
```

**Allow Gas**
```
Turn this on if you want to step on the gas pedal while dragonpilot is engaged.
```

**Enable Steering On Signal**
```
Turn this on if you want to temporary disable dragonpilot's lateral control when blinker/singal is on.
```

**Display "Turn Exceeds Steering" Limit" Alert**
```
Cars like Honda has limited steering angle/torque, when the curvature is higher than the limitation, dragonpilot sends alerts to warn the driver,
Disable this will stop any of those alerts.
(Hyundai, Ford, Toyota do not use such alert)
```

**Enable Slow on Curve**
```
Disable this if you do not wish to slow down on curve automatically.
```

**Enable Lead Car Moving Alert**
```
dragonpilot will send an alert when:
a lead car stopped in front of you for more than 0.5s and started moving

This works better if you turn on Toyota > Stock DSU Mode
```

**Enable Assisted Lane Change**
```
This is a hidden feature by comma ai in 0.7. 
Once it's enabled, if your speed reach 37mph / 60kph or above and has left or right blinker on, it will help you to change lane when you apply a small force on the steering wheel (of the same direction as the blinker).
NOTE: if you do not turn off your blinker, you can apply force again to change to the next lane. 
```

**Enable Auto Lane Change**
```
This option will appear when the "Enable Assisted Lane Change" is enabled.
If your speed reach 60mph / 97kph or above and has left or right blinker on, it will help you to change lane with a 3 seconds delay.
You can override the 3 seconds delay by applying force on the steering wheel.
NOTE: if you do not turn off your blinker, it will keep changing to the next lane (3 seconds delay applied).   
```

**Enable Safety Check**
```
This is the main switch for all safety checks, if you disable this, dragonpilot will stop all safety checks (steering monitor and driver monitor).
```

**Enable Driver Monitoring**
```
Driver monitoring is permenantly on since 0.6.4 and this option will let you enable/disable driver monitoring.
```

**Steering Monitor Timer**
```
This option allows you to adjust the timer for steering monitor, set it to 0 if you do not wish to monitor through steering wheel.
```

UI Settings
-
**Display Driving UI**
```
Disable this will hide camera footage from the screen and leaves you only the sidebar and the rest of the UI components (that can be enable/disable below).
It's good for using with TomTom or any other android apps run in full screen mode.
```

**Boost Audio Alert Volume (%)**
```
This allow you to adjust the warning alert sounds, the system adjust volume based on the speed of the car, and this option can increase/decrease the volume
of top of that.
(range: -100 to 100)
```

Toyota/Lexus Settings
-
**Enable Stock DSU Mode**
```
This is for TSS1 cars w/ DSU connected, once this is enabled, dragonpilot can be engaged via 1. ACC and/or 2. AHB toggle.
With AHB switch toggle, dragonpilot will stay engaged all time for lateral control and wont be disengaged if step on gas or brake.
```

**Enable Lane Departure Warning**
```
Disable this will stop reciving Lane Departure warning (alerts/steering wheel vibration).
```

**Enable SnG Mod**
```
Enable this will apply stop n go hack, see https://github.com/commaai/openpilot/pull/741 for more information.
```

3rd Party Apps
-
**Enable Waze Mode**
```
Enable this will turn your EON into a Waze Navigator,  once it's enabled:
1. It will disable Tomtom/Autonavi/Aegis apps.
2. It will disable most of the driving UI elements. (you still see all the warnings.)
3. Once the car is started, Waze will start automatically.
4. Once Waze is started, you cannot make any changes to the DP settings*.
   (* We need to disable frame app to enable soft keyboard.)
```