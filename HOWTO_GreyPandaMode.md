什麼是 GreyPandaMode
---
如果您的 EON 用的是灰熊(Grey Panda)，您可以讓 dragonpilot 裡的**tomtom/高德地圖 (或是其它的 GPS 應用程式)**使用灰熊的高精度數據。

優點：
1. 達到 10 公分以內的精度 (最佳狀況下)
2. 30 秒以內定位完成 (最佳狀況下)

缺點：
1. 斷開後無法定位
2. 可能不適用於其它應用程式


安裝方法
---
1. 請先確認您的 dragonpilot 在 0.6.3 以後的版本
2. [SSH] 打開設定頁面: 
    ```bash
    am start -a android.settings.SETTINGS
    ```
3. [ANDROID] 點選「開發人員選項」
4. [ANDROID] 找到「選取模擬位置應用程式」
5. [ANDROID] 選擇
    ```bash
    Black
    ai.comma.plus.black
    ```
6. [SSH] 開啟 DragonGreyPandaMode 設定
    ```bash
    echo 1 > /data/params/d/DragonGreyPandaMode
    ```
7. [SSH] 重新開機
    ```bash
    reboot
    ```
    
反安裝方法
---
1. [SSH] 開閉 DragonGreyPandaMode 設定
    ```bash
    echo 0 > /data/params/d/DragonGreyPandaMode
    ```
2. [SSH] 打開設定頁面: 
    ```bash
    am start -a android.settings.SETTINGS
    ```
3. [ANDROID] 點選「開發人員選項」
4. [ANDROID] 找到「選取模擬位置應用程式」
5. [ANDROID] 選擇
    ```bash
    無
    ```
7. [SSH] 重新開機
    ```bash
    reboot
    ```
