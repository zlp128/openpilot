**YOU HAVE BEEN WARNED**
---
![](warning.jpg)

SWITCH OVER COMMAND
---
```bash
cd /data/ && mv openpilot op_backup_$(date +%Y%m%d%H%M%S) && git clone https://github.com/dragonpilot-community/dragonpilot.git openpilot -b devel-i18n && cd openpilot/scripts/ && ./reset_update.sh
```

dragonpilot (aka dp)
---
dragonpilot is a modded version of [openpilot](https://github.com/commaai/openpilot/) with features including:  

* Multi-language interface (Fully support: English, Simplified/Traditional Chinese, partial support: Japanese, Korean, French, Portuguese, German)
* drive recording.
* Configurable driving UI.
* Auto Shutdown.
* Temporarily disable steering control when Turn signal / direction light is on.
* Disallow AI training video recording.
* Disallow upload of AI training video recording.
* Allow gas/throttle access while engaging.
* Full Speed Fan Mode.
* Ability to disable driver monitoring.
* ACC Only Mode: No steering assist.
* Integrated with TOM TOM Speed Camera (Global) / Autonavi (China) / Ainvest (Taiwan) / Waze (Global).
* Allow Panda/C2 GPS signal passthru to 3rd Party Apps. 
* Integrated with MiXplorer File Manager.
* Display WIFI IP Address on sidebar.
* Automated Lane Change.
* Enable Hotspot/Tethering on Boot.
* Adjustable Lead Car Following Profile. (longitudinal, aka Dynamic Following by @ShaneSmiskol: https://github.com/ShaneSmiskol/)
* Turn off screen while reversing. (by @mlp: https://github.com/martinl/)
* Turn off screen while driving.
* Custom Car Model selector. (fingerprint-less mode)

Additional Model Support
---
We support the following additional car models (v0.6.4+):
* China Honda Inspire Hybrid by KT
* China Honda Accord Hybrid
* China 2018 Toyota Camry 2.0 by Rming
* China 2018 Toyota Highlander by toyboxZ
* China 2018 Toyota Camry by 笨木匠
* China 2020 Toyota RAV4 by 笨木匠
* China 2019 Toyota Levin (Petrol) by Shell
* China 2019 Lexus RX300 by cafe
* China 2019 Toyota Corolla (Petrol) by Shell
* Taiwan 2016 Toyota Prius by Philip
* Taiwan 201? Toyota RAV4 4WD 5th Gen by Philip
* Taiwan 2020 Toyota Auris w/ LTA by Philip
* Taiwan 2017 Lexus IS200t by Philip / Cody Dai
* Taiwan 2019 Toyota RAV4 Hybrid by MaxDuan
* Taiwan 2019 Toyota RAV4 by MaxDuan / CloudJ
* Taiwan 2019 Toyota Corolla Altis by wlee72
* Taiwan Lexus CT200h by CloudJ
* Taiwan Toyota Prius 4.5 Gen by Lin Xin Hong
* Taiwan 2017 Lexus GS450h by 簡銘佑
* Poland 2015 Lexus NX200T by wabes

We supports the following brand majorly:
* Lexus / Toyota
* Honda
* Hyundai
(Other openpilot supported cars/brands are partially supported.)

Screenshots
---
![](dp_1.png) ![](dp_2.png) ![](dp_3.png) ![](dp_4.png) ![](dp_5.png) ![](dp_6.png)

**Please see screenshots/ Folder**

Videos
---
<table>
  <tr>
    <td><a href="https://www.youtube.com/watch?v=-Womm0aO8Cc" title="YouTube" rel="noopener"><img src="http://i3.ytimg.com/vi/-Womm0aO8Cc/hqdefault.jpg"></a></td>
    <td><a href="https://www.youtube.com/watch?v=ACrHqodnhKI" title="YouTube" rel="noopener"><img src="http://i3.ytimg.com/vi/ACrHqodnhKI/hqdefault.jpg"></a></td>
    <td><a href="https://www.youtube.com/watch?v=lovEJU_Y7eI" title="YouTube" rel="noopener"><img src="http://i3.ytimg.com/vi/lovEJU_Y7eI/hqdefault.jpg"></a></td>
    <td><a href="https://www.youtube.com/watch?v=fb0KEZgqH1Y" title="YouTube" rel="noopener"><img src="http://i3.ytimg.com/vi/fb0KEZgqH1Y/hqdefault.jpg"></a></td>
  </tr>
</table>

Installation
---
 
1. SSH into your device
2. Switch to /data/ directory 
    ```bash
    cd /data
    ```
3. back up existing openpilot (optional)
    ```bash
    mv openpilot openpilot_bak
    ```
4. download dragonpilot development version to openpilot directory from github or gitee:
    * github 
    ```bash
    git clone https://github.com/dragonpilot-community/dragonpilot.git openpilot -b devel-i18n
    ```
    * gitee
    ```bash 
    git clone https://gitee.com/dragonpilot-community/dragonpilot.git openpilot -b devel-i18n
    ```
5. switch into openpilot directory
    ```bash
    cd openpilot
    ```
6. update git repository again just in case
    ```bash
    git pull
    ```
7.  Reboot
    ```bash
    reboot
    ```

**Please reboot again if you have display issue. (Chinese / Japanese / Korean only)**

Update
---
1. switch to /data/openpilot directory 
    ```bash
    cd /data/openpilot/scripts/
    ```
2. run update command
    ```bash
    ./reset_update.sh
    ```

Versions
---
* docs: Manual
* testing: Alpha quality - (i18n，Based on openpilot devel-staging/devel branch + customisation + new features, may contain bugs/errors)
* feature-????: new feature testing branch - (i18n，based on dp testing branch + customisation + new features, may contain bugs/errors)
* devel-i18n: beta quality - (i18n, based on dp testing branch, less bugs/errors)
* ?.?.?-i18n: stable release - (i18n, based on devel-i18n branch, more stable than devel-i18n but may still contain bugs/errors)

**Always stick with beta/stable version unless you know what you are doing.**
