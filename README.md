<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#org11a15c8">1. 免責事項</a></li>
<li><a href="#orge3a3040">2. 特徴</a></li>
<li><a href="#org36df7e1">3. 対象</a></li>
<li><a href="#org9d41c60">4. 使用方法</a>
<ul>
<li><a href="#org5c21fe4">4.1. cmake、gitのインストール</a></li>
<li><a href="#orgc22aef3">4.2. 仮想環境を用いている場合</a></li>
<li><a href="#org154e430">4.3. プロジェクトのコンパイル</a></li>
<li><a href="#org624ced0">4.4. プロジェクトの実行</a></li>
</ul>
</li>
<li><a href="#org5aaa1b4">5. デフォルトのキーバインド</a>
<ul>
<li><a href="#org62a0efe">5.1. MODE1</a></li>
<li><a href="#orgc1ec287">5.2. MODE2</a></li>
</ul>
</li>
</ul>
</div>
</div>
    (require 'ox-qmd)


<a id="org11a15c8"></a>

# 免責事項

公開しているソフトウェア、および同梱のファイルの使用、またはバグにより生じたいかなる損害に関しまして作者は一切責任を負いません。


<a id="orge3a3040"></a>

# 特徴

-   このmousekeyはホームポジションでマウスカーソルを動かすソフトウェアである。
-   マウスを動かすキーボードのキーは自分で設定することができる。


<a id="org36df7e1"></a>

# 対象

-   Ubuntu16.04とUbuntu14.04とpi-topOSでは動くことを確認した。
-   おそらくLinux全般で動くと思われる。（動作報告をしてほしい。）
-   macOSやwindowsOSは対象ではない。


<a id="org9d41c60"></a>

# 使用方法


<a id="org5c21fe4"></a>

## cmake、gitのインストール

cmakeをインストールしていない人はまずcmakeをインストールします。
以下コマンド
sudo apt install cmake
sudo apt install git


<a id="orgc22aef3"></a>

## 仮想環境を用いている場合

マウス統合を解除することによって使えるようになります。


<a id="org154e430"></a>

## プロジェクトのコンパイル

git clone <https://bitbucket.org/hemuhemu33/mousekey.git>
cd mousekey
cd exec
sh build.sh


<a id="org624ced0"></a>

## プロジェクトの実行

-   以下実行コマンド(管理者権限が必要)

sudo ./mousekey
バックグラウンドで動かす場合、
sudo ./mousekey &


<a id="org5aaa1b4"></a>

# デフォルトのキーバインド

設定はtest.confに記載。自由にカスタマイズできます。KEY\_●の●の部分を変えるだけです。


<a id="org62a0efe"></a>

## MODE1

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<tbody>
<tr>
<td class="org-left">変換+q</td>
<td class="org-left">プログラムの終了</td>
</tr>


<tr>
<td class="org-left">変換+f</td>
<td class="org-left">マウスを右にすすめる</td>
</tr>


<tr>
<td class="org-left">変換+b</td>
<td class="org-left">マウスを左にすすめる</td>
</tr>


<tr>
<td class="org-left">変換+p</td>
<td class="org-left">マウスを上にすすめる</td>
</tr>


<tr>
<td class="org-left">変換+n</td>
<td class="org-left">マウスを下にすすめる</td>
</tr>


<tr>
<td class="org-left">変換+a</td>
<td class="org-left">マウスのスピードを下げる</td>
</tr>


<tr>
<td class="org-left">変換+e</td>
<td class="org-left">マウスのスピードを上げる</td>
</tr>


<tr>
<td class="org-left">変換+sapce</td>
<td class="org-left">左クリック</td>
</tr>


<tr>
<td class="org-left">変換+l</td>
<td class="org-left">右クリック</td>
</tr>


<tr>
<td class="org-left">変換+i</td>
<td class="org-left">ホイールを上に回す</td>
</tr>


<tr>
<td class="org-left">変換+k</td>
<td class="org-left">ホイールを下に回す</td>
</tr>


<tr>
<td class="org-left">変換+w</td>
<td class="org-left">ホイールクリック</td>
</tr>


<tr>
<td class="org-left">変換+u</td>
<td class="org-left">ブラウザの次へボタン</td>
</tr>


<tr>
<td class="org-left">変換+j</td>
<td class="org-left">ブラウザの戻るボタン</td>
</tr>


<tr>
<td class="org-left">変換+c</td>
<td class="org-left">MODE2にする。(モードを増やしたら他のモードになる)</td>
</tr>
</tbody>
</table>


<a id="orgc1ec287"></a>

## MODE2

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<tbody>
<tr>
<td class="org-left">変換+h</td>
<td class="org-left">BackSpace</td>
</tr>


<tr>
<td class="org-left">変換+d</td>
<td class="org-left">Delete</td>
</tr>


<tr>
<td class="org-left">変換+a</td>
<td class="org-left">Home</td>
</tr>


<tr>
<td class="org-left">変換+e</td>
<td class="org-left">End</td>
</tr>


<tr>
<td class="org-left">変換+m</td>
<td class="org-left">Enter</td>
</tr>


<tr>
<td class="org-left">変換+n</td>
<td class="org-left">down</td>
</tr>


<tr>
<td class="org-left">変換+f</td>
<td class="org-left">right</td>
</tr>


<tr>
<td class="org-left">変換+p</td>
<td class="org-left">up</td>
</tr>


<tr>
<td class="org-left">変換+b</td>
<td class="org-left">left</td>
</tr>


<tr>
<td class="org-left">変換+c</td>
<td class="org-left">MODE1にする</td>
</tr>
</tbody>
</table>

