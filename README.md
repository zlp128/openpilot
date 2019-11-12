dragonpilot (龍芯駕駛輔助系統)
---
龍芯駕駛輔助系統是一套基於 [openpilot](https://github.com/commaai/openpilot/) 的開源 L2 級自動駕駛系統軟體，它可以升級您車子裡的 ACC (主動式定速巡航系統) 以及 LKAS (車道保持輔助系統) 至接近特斯拉 Autopilot 的等級。 

龍芯駕駛輔助系統在 openpilot 的基礎上加入更多客制化的功能，目前有：

* 中文化介面 (简体/繁體)
* 不間斷行車記錄
* 可設定的行車介面
* 斷電自動關機
* 轉向燈/方向燈暫時取消控制
* 停止 AI 訓練記錄
* 取消 AI 訓練記錄上傳
* 允許油門：dp 控制時可踩油門
* Noctua 風扇模式
* 完全取消駕駛監控 (人臉+方向盤)
* ACC 模式：讓 dp 只操控油門/剎車
* TOM TOM 測速照相 / 高德地圖
* MiXplorer 檔案管理器
* 側邊欄顯示無線網路 IP 位置
* TOM TOM 測速照相 / 高德地圖使用 Grey Panda 數據 (請參閱 HOWTO_GreyPandaMode.md 說明檔)

**更多客制化內容請參閱 [CHANGELOG.md](CHANGELOG.md)**

支援車款
---
除了官方支援的車款外，dp (0.6.4+) 還支援以下車款：
* 大陸版東風本田 Inspire 混動 by KT
* 大陸版本田雅閣混動 
* 台灣版 2019 Toyota RAV4 Hybrid by MaxDuan
* 台灣版 2019 Toyota RAV4 by MaxDuan / CloudJ
* 台灣版 2019 Toyota Corolla Altis by wlee72
* 台灣版 Lexus CT200h by CloudJ
* 台灣版 Toyota Prius 4.5 代 by Lin Xin Hong
* 台灣版 2017 Lexus GS450h by 簡銘佑
* ~~大陸版本田奧德賽 by eFiniLan (已入官方)~~
* ~~大陸版本田 CR-V by eFiniLan (已入官方)~~
* ~~美國版 2018 Lexus CT200h by thomaspich (已入官方)~~
* ~~澳洲版 2017 Lexus IS300h by eFiniLan (已入官方)~~
* ~~台灣版 2019 Toyota Corolla Altis 油電版 by wlee72 (已入官方)~~


畫面截圖
---
![](dp_1.png) ![](dp_2.png) ![](dp_3.png) ![](dp_4.png) ![](dp_5.png) ![](dp_6.png)

**更多請看 screenshots/ 資料夾**


硬體需求
---
* 一加 oneplus 3t 或者 樂視 LeEco Le Pro3 (x727) 手機 / EON
* Panda
* Giraffe
* 適配的車款


硬件購買
---
您可以至以下的渠道購買相關硬件 (EON / Panda / Giraffe)：

* comma ai 官方: https://comma.ai/shop/
* Taobao: https://shop442817640.taobao.com/

**我們並沒有與任何渠道商合作，若有任何問題請直接與他們聯系**


安裝 NEOS
---
待補充


安裝 dragonpilot
---
 
1. SSH 至手機後
2. 切換至 /data/ 資料夾 
    ```bash
    cd /data
    ```
3. 備份舊版的 openpilot
    ```bash
    mv openpilot openpilot_bak
    ```
4. 下載 dragonpilot 英文開發版並存至 openpilot 資料夾 (2 選 1):
    1. github 
    ```bash
    git clone https://github.com/dragonpilot-community/dragonpilot.git openpilot --branch devel-en
    ```
    2. gitee
    ```bash 
    git clone https://gitee.com/dragonpilot-community/dragonpilot.git openpilot --branch devel-en
    ```
5. 切換到 openpilot 的資料夾
    ```bash
    cd openpilot
    ```
6. 更新 git 資料庫
    ```bash
    git pull
    ```
7. 切換想使用的版本/語系分支 (預設為英文開發版，不想切換可省略此步驟)
    ```bash
    # 简体开发版
    #git checkout devel-zhs
    # 繁體開發版
    #git checkout devel-zht
    # 简体稳定版 v0.6.5
    #git checkout 0.6.5-zhs      
    # 繁體穩定版 v0.6.5
    #git checkout 0.6.5-zht
    ```
8. 確認沒有錯誤
    ```bash
    make
    ```
9.  重開機
    ```bash
    reboot
    ```
10. 手動更新 Panda 韌體
    ```bash
    cd /data/openpilot/panda ; pkill -f boardd ; PYTHONPATH=..; python -c "from panda import Panda; Panda().flash()"
    ```

**如果重開機後中文字無法正確顯示，請再重開機一次。**


更新 dragonpilot
---
1. 切換至 /data/openpilot 資料夾 
    ```bash
    cd /data/openpilot
    ```
2. 撤消所有手動的變更
    ```bash
    git reset --hard
    ```
3. 更新 git 資料庫
    ```bash
    git pull
    ```
4. 切換到新的版本分支 (使用的是 devel 版可省略此步驟)
    ```bash
    # 简体开发版
    #git checkout devel-zhs
    # 繁體開發版
    #git checkout devel-zht
    # 简体稳定版 v0.6.5
    #git checkout 0.6.5-zhs      
    # 繁體穩定版 v0.6.5
    #git checkout 0.6.5-zht
    ```
5. 確認沒有錯誤
    ```bash
    make
    ```
6.  重開機
    ```bash
    reboot
    ```
7. 手動更新 Panda 韌體
    ```bash
    cd /data/openpilot/panda ; pkill -f boardd ; PYTHONPATH=..; python -c "from panda import Panda; Panda().flash()"
    ```

版本分支介紹
---
* docs: 說明檔
* devel-unsupported-cars: 官方原版 + 方便移植新車款用的補丁。
* devel-en: 開發版 - (英文，基於官方原版 + 客制化功能)
* devel-zhs: 開發版 - (简体中文，基於 devel-en + 简体中文化)
* devel-zht: 開發版 - (繁體中文，基於 devel-en + 繁體中文化)
* ?.?.?-en: 穩定版 - (英文，測試過的 devel-en)
* ?.?.?-zhs: 穩定版 - (简体中文，測試過的 devel-zhs)
* ?.?.?-zht: 穩定版 - (繁體中文，測試過的 devel-zht)

**其它沒有說明的分支為測試功能版，非必要請勿使用**
