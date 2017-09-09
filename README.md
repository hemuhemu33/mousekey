- [免責事項](#org1b72396)
- [特徴](#org8a4cfaa)
- [対象](#orge026c5f)
- [使用方法](#org4521d0e)
  - [cmake、gitのインストール](#orgfda0295)
  - [仮想環境を用いている場合](#orge6d53e5)
  - [プロジェクトのコンパイル](#org2d097bf)
  - [プロジェクトの実行](#orgfd02890)
- [デフォルトのキーバインド](#orge60f246)
  - [MODE1](#orgca6d163)
  - [MODE2](#orgc1db0b1)

```emacs-lisp
(require 'ox-qmd)
```


<a id="org1b72396"></a>

# 免責事項

公開しているソフトウェア、および同梱のファイルの使用、またはバグにより生じたいかなる損害に関しまして作者は一切責任を負いません。


<a id="org8a4cfaa"></a>

# 特徴

-   このmousekeyはホームポジションでマウスカーソルを動かすソフトウェアである。
-   マウスを動かすキーボードのキーは自分で設定することができる。


<a id="orge026c5f"></a>

# 対象

-   Ubuntu16.04とUbuntu14.04とpi-topOSでは動くことを確認した。
-   おそらくLinux全般で動くと思われる。（動作報告をしてほしい。）
-   macOSやwindowsOSは対象ではない。


<a id="org4521d0e"></a>

# 使用方法


<a id="orgfda0295"></a>

## cmake、gitのインストール

cmakeをインストールしていない人はまずcmakeをインストールします。 以下コマンド sudo apt install cmake sudo apt install git


<a id="orge6d53e5"></a>

## 仮想環境を用いている場合

マウス統合を解除することによって使えるようになります。


<a id="org2d097bf"></a>

## プロジェクトのコンパイル

git clone <https://bitbucket.org/hemuhemu33/mousekey.git> cd mousekey cd exec sh build.sh


<a id="orgfd02890"></a>

## プロジェクトの実行

-   以下実行コマンド(管理者権限が必要)

sudo ./mousekey バックグラウンドで動かす場合、 sudo ./mousekey &


<a id="orge60f246"></a>

# デフォルトのキーバインド

設定はtest.confに記載。自由にカスタマイズできます。KEY\_●の●の部分を変えるだけです。


<a id="orgca6d163"></a>

## MODE1

| 変換+q   | プログラムの終了             |
| 変換+f   | マウスを右にすすめる         |
| 変換+b   | マウスを左にすすめる         |
| 変換+p   | マウスを上にすすめる         |
| 変換+n   | マウスを下にすすめる         |
| 変換+a   | マウスのスピードを下げる     |
| 変換+e   | マウスのスピードを上げる     |
| 変換+sapce | 左クリック                   |
| 変換+l   | 右クリック                   |
| 変換+i   | ホイールを上に回す           |
| 変換+k   | ホイールを下に回す           |
| 変換+w   | ホイールクリック             |
| 変換+u   | ブラウザの次へボタン         |
| 変換+j   | ブラウザの戻るボタン         |
| 変換+c   | MODE2にする。(モードを増やしたら他のモードになる) |


<a id="orgc1db0b1"></a>

## MODE2

| 変換+h | BackSpace |
| 変換+d | Delete    |
| 変換+a | Home      |
| 変換+e | End       |
| 変換+m | Enter     |
| 変換+n | down      |
| 変換+f | right     |
| 変換+p | up        |
| 変換+b | left      |
| 変換+c | MODE1にする |