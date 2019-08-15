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
* [0.6.3] TOM TOM 測速照相 / 高德地圖


畫面截圖
---
![](dp_1.png) ![](dp_2.png) ![](dp_3.png) ![](dp_4.png) ![](dp_5.png)

硬體需求
---
* 一加 oneplus 3t 或者 樂視 LeEco Le Pro3 (x727) 手機
* Panda
* Giraffe
* 適配的車款


安裝 NEOS
---
待補充


安裝 dragonpilot
---
 
SSH 至手機後
 
```bash
# 切換至 /data/ 資料夾
cd /data

# 備份舊版的 openpilot
mv openpilot openpilot_bak

# 下載 dragonpilot 並命名為 openpilot
# 若是 github 太慢，也可以使用我們的 gitee 鏡像: 
# git clone https://gitee.com/dragonpilot-community/dragonpilot.git openpilot
git clone https://github.com/dragonpilot-community/dragonpilot.git openpilot

# 切換到 openpilot 的資料夾
cd openpilot

# 更新 git 資料庫
git pull

#################################
## 切換想使用的語系，以下三選一
## 0.6.2 可換成不同的版本
#################################

# (英文)
git checkout 0.6.2-en

# 或是

# (简体中文)
git checkout 0.6.2-zhs

# 或是

# (繁體中文）
git checkout 0.6.2-zht

#################################
## 三選一結束
#################################

# 確認沒有錯誤
make

# 重開機
reboot
```

分支介紹
---
* docs: 說明
* devel-en: 開發版 - (英文, 基於官方原版 + 客制化功能)
* devel-zhs: 開發版 - (简体中文, 基於 devel-en + 简体中文化)
* devel-zht: 開發版 - (繁體中文, 基於 devel-en + 繁體中文化)
* ?.?.?-en: 穩定版 - (英文, 測試過的 devel-en)
* ?.?.?-zhs: 穩定版 - (简体中文, 測試過的 devel-zhs)
* ?.?.?-zht: 穩定版 - (繁體中文, 測試過的 devel-zht)

其它沒有說明的分支為測試功能版，非必要請勿使用