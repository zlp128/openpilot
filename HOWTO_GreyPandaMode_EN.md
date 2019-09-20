What is GreyPandaMode
---
If you are using Grey Panda, this mode will allow the grey panda GPS data available to TomTom/Autonavi apps included in the dragonpilot (and probably other navigation apps). 

Pros:
1. Precise GPS data.
2. Lock your location in under 30 seconds.

Cons:
1. Unable to located after you car is off.
2. May not suitable to other app.

How to install
---
1. Please make sure your dragonpilot is 0.6.4+ or devel.
2. [SSH] Open Android Settings: 
    ```bash
    am start -a android.settings.SETTINGS
    ```
3. [ANDROID] Find the "Developer Options", if this is not available, find "About" and click "Version Number" several time.
4. [ANDROID] Click "Developer Options"
5. [ANDROID] Find "Select Mock Location App"
6. [ANDROID] Select
    ```bash
    cn.dragonpilot.gpsservice
    cn.dragonpilot.gpsservice
    ```
6. [SSH] Enable DragonGreyPandaMode Settings
    ```bash
    printf %s "1" > /data/params/d/DragonGreyPandaMode
    ```
7. [SSH] Reboot
    ```bash
    reboot
    ```
    
How To uninstall
---
1. [SSH] Disable DragonGreyPandaMode Settings
    ```bash
    printf %s "0" > /data/params/d/DragonGreyPandaMode
    ```
2. [SSH] Open Android Settings
    ```bash
    am start -a android.settings.SETTINGS
    ```
3. [ANDROID] Click "Developer Options"
4. [ANDROID] Find "Select Mock Location App"
5. [ANDROID] Select
    ```bash
    無
    ```
7. [SSH] Reboot
    ```bash
    reboot
    ```

FAQ
---
```
Q. Does this only work in dragonpilot? 
A. No, all you need is copy the /data/openpilot/cn.dragonpilot.gpsservice.apk to your /data/openpilot/apk and follow the instruction above, you will need to start the service manually. 
```
```
Q. Does it support XXXXXXXX app? 
A. It will work as long as it allows "Mock location app", so no Pokemon Go! :)
```
```
Q. Why I see cn.dragonpilot.gpsservice crashed
A. This is because the service is started before it's been assigned to "Mock location app", try re-assign it and see how it goes.
```
```
Q. Why I see Taoyuan City on the dp home screen？
A. This is to make sure the setting is correct, I'm from Taiwan Taoyuan XD
```