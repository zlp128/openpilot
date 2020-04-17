dragonpilot
---
dragonpilot is a modded version of [openpilot](https://github.com/commaai/openpilot/), we have additional features including:  

* Multi-language interface (current support: English, Simplified, Traditional, partial support: Japanese, Korean, French, Portuguese)
* Non-stop dashcam recording
* Configurable driving interface
* Auto Shutdown (not applicable for Comma Two or Comma Power users)
* Temporarily disable steering control when Turn signal / direction light is on.
* Disallow AI training recording.
* Disallow upload of AI training recording.
* Allow gas/throttle control while engaging.
* Noctua Fan Mode (Fan runs at full speed all time).
* Adjustable driver monitoring.
* ACC Only Mode: Only control gas / brake when engaging.
* Integrated with TOM TOM Speed Camera (Global) / Autonavi (China) / Ainvest (Taiwan) / Waze (Global).
* Allow Panda GPS passthru to 3rd Party Apps. 
* Integrated with MiXplorer File Manager.
* Display WIFI IP Address on sidebar.
* Automated Lane Change.
* Hotspot on Boot.
* Adjustable Acceleration Profile (longitudinal Control required, by @arne182)
* Adjustable Lead Car Following Profile (longitudinal, aka Dynamic Following by @ShaneSmiskol)

** Please see [FEATURES_EN.md](FEATURES_EN.md) for more information.**

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
    <td><a href="https://www.youtube.com/watch?v=D5M5qci5wsw" title="YouTube" rel="noopener"><img src="http://i3.ytimg.com/vi/D5M5qci5wsw/hqdefault.jpg"></a></td>
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
3. back up existing openpilot
    ```bash
    mv openpilot openpilot_bak
    ```
4. download dragonpilot development version to openpilot directory from github or gitee:
    * github 
    ```bash
    git clone https://github.com/dragonpilot-community/dragonpilot.git openpilot --branch devel-i18n
    ```
    * gitee
    ```bash 
    git clone https://gitee.com/dragonpilot-community/dragonpilot.git openpilot --branch devel-i18n
    ```
5. switch into openpilot directory
    ```bash
    cd openpilot
    ```
6. update git repository
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
    cd /data/openpilot
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
