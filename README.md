dragonpilot (龍芯駕駛輔助系統)
---
龍芯駕駛輔助系統是一套基於 [openpilot](https://github.com/commaai/openpilot/) 的開源 L2 級自動駕駛系統軟體，它可以升級您車子裡的 ACC (主動式定速巡航系統) 以及 LKAS (車道保持輔助系統) 至接近特斯拉 Autopilot 的等級。 

龍芯駕駛輔助系統在 openpilot 的基礎上加入更多客制化的功能，目前有：

* 中文化介面 (简体/繁體)
* 不間斷行車記錄
* 簡潔的行車介面
* 優化路線預測
* 斷電自動關機


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
git clone https://github.com/dragonpilot-community/dragonpilot-release.git openpilot

# 切換到 openpilot 的資料夾
cd openpilot

# 更新 git 資料庫
git pull

#################################
## 切換想使用的語系，以下二選一
#################################

# (简体中文)
git checkout release-zhs

# 或是

# (繁體中文）
git checkout release-zht

#################################
## 二選一結束
#################################

# 確認沒有錯誤
make

# 重開機
reboot
```