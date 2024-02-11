# MGSPICO
2024/02/11 harumakkin

![mgspico-03](docs/pics/mgspico.png)
**fig.1 MGSPICO**

## これは何？
MSX本体が無くてもFM音源カートリッジとMGSDRVを使用してMGS楽曲データを再生し鑑賞できる個人製作のハードウェアです。MGSDRV は Raspberry Pi Pico内で動作しますがRP2040用に移植した、というものではなくMSX用のMGSDRVを、HopStepZというMGSDRV専用エミュレータを使用して動作させています。

## 使い方
### 用意するもの
- MGSPICO
- MGSDRV.COM(Ver3.20)  https://gigamix.hatenablog.com/entry/mgsdrv/
- MGS楽曲データファイル
- microSD カード
- FM音源カートリッジ
- SCC音源カートリッジ
- DC5V電源(microUSB、もしくは、センタープラス 2.1mm DCプラグ）

#### 動作確認済みFM音源/SCC音源カートリッジ
FM音源カートリッジは、下記で動作することを確認しています。
|音源|カートリッジ|参考URL|
|:-|:-|:-|
|PSG/OPLL|SoundCoreSLOT EX|http://niga2.sytes.net/sp/coreslot.pdf|
|PSG/OPLL|MSX SOUND ENHANCER|https://www.kadenken.com/view/item/000000001175|
|SCC|MSX2版 スナッチャー 付属SCCカートリッジ|-|
|SCC|MSX版 SALAMANDER カートリッジ|-|

## microSD カードの準備
- microSDカードを用意します。（32GBの容量の物で動作確認しています、それ以外では行っていません）
- microSDカードを、FAT、もしくは、FAT32フォーマットを施します。
- microSDカードに、MGSDRV.COM、player.com をコピーします
- また、鑑賞したいMGSデータファイル(.MGS)もカードへコピーします（1000ファイルまで）

## セットアップする
- microSDカードをMGSPICOのスロットに取り付ける
- FM音源／SCC音源を取り付ける
- AudioOutにスピーカーなどを取り付ける
- MGSPICO に電源を取り付ける。microUSB or DCプラグ（電圧と極性を間違わないこと！）

![ex1](docs/pics/ex1.png)
![ex2](docs/pics/ex2.png)
fig.2 セットアップ例

## 操作方法
- 問題なく起動すれば、microSD内の最大3つのMGSファイルの名前が表示されます
- ▲／▼ スイッチでファイルを選択できます
- ● スイッチで、再生を開始します、同じファイルを選択した状態でもう一度押すと再生を停止します。

## トラブルシュート
1. "Not found MGSDRV.COM"、"Not found PLAYER.COM" と表示される。この場合は次のことが考えられます
	- microSDカードが正しく挿入されていない。フォーマットし直しや、容量を変更を個なってみてください
	- microSDカードにMGSDRV.COM、PLAYER.COMが正しく格納されていない。格納されているか確認してください
2. MSX SOUND ENHANCERとSCCを組み合わせるて使用するケースでFM音源が鳴らない
	- MGSPICOの電源をSW2を押しながら入れると解決します（ファイルリストが表示されるまでの１秒間押します）
	- MSX SOUND ENHANCERはFM音源認識用ダミーROMを持っていますが、SCCカートリッジをパススルースロットで使用するためにこのROMを切り離す設定にしているかと思います。そのためMGSDRVがFM音源認識できずFM音源のデータを再生しません。MGSPICOの電源をSW2を押しながら入れるとMGSPICOが持つFM音源認識用ダミーROMと同じことをMGSDRVに対して行いますので、MGSDRVがFM音源があるものとして動作します。

## ガーバーデータと部品表
- MGS-PICO-XXX/ ディレクトリ内を参照のこと。はんだ付けの難度は高いです。
- raspberry Pi Picoにインストールするファイルは、RasPiPico/dist/mgspico.uf2 です

# LICENSEと利用に関する注意事項
1. MGSPICOのファームウェアとそのソースコード、回路図データおよび資料ファイルは MIT License で配布されます。ただし、MGSPICO は、FatFsと8x16文字フォントを使用しています。FatFs/8x16文字フォントのソースコードの扱いに関しては各々のLICENSEに従ってください。
2. 本作品は同人ハードウェア＆ソフトウェアです。本作品の設計およびソフトウェアは品質を保証していません。音源カートリッジや音響設備、その周辺機器が故障、破損したとしても自身で責任を負える方のみ本作品をご利用ください。特にハードウェアの製作を伴いますのでリスクがあります。製作の腕に自身のある方のみご利用ください。
3. 本作品の設計資料とソースコードの改変や改造、また、別の作品への利用、商用利用は自由です。ただし、1. 2.の制限を超える利用は各自でその責任と義務を負ってください。

## MGSPICOが使用しているソフトウェア(SDK以外)
- FatFs Copyright (C) 20xx, ChaN, all right reserved. http://elm-chan.org/fsw/ff/00index_e.html
- 8x16 文字フォント FONT8X16MIN.h https://github.com/askn37/OLED_SSD1306

## 修正履歴
- MGSPICO-03A

## 余禄
MGSPICOの機能に関係ないですが、開発中に見つけたものをメモ書きしておきます。
- SoundCoreSLOT EXへは、CLOCK信号を供給しなくても鳴ります。自前のクリスタルを内蔵しているようです。ただしFMPACKと同様±12Vの供給は必要です。MSX SOUND ENHANCERはCLOCK信号の供給は必須ですが、±12Vは必要ありません。音質へのこだわりなのだと思うのですが二者のアプローチの違いが面白いです。




