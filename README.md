<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#orge4b9ebf">1. 免責事項</a></li>
<li><a href="#org9b5ee37">2. 特徴</a></li>
<li><a href="#org0a73d47">3. 対象</a></li>
<li><a href="#org057518f">4. 使用方法</a>
<ul>
<li><a href="#org849bda8">4.1. cmake、gitのインストール</a></li>
<li><a href="#orga95e7f9">4.2. 仮想環境を用いている場合</a></li>
<li><a href="#org2f42928">4.3. プロジェクトのコンパイル</a></li>
<li><a href="#org706eb82">4.4. プロジェクトの実行</a></li>
</ul>
</li>
<li><a href="#orgef35f62">5. デフォルトのキーバインド</a>
<ul>
<li><a href="#org2d406c8">5.1. MODE1</a></li>
<li><a href="#org24c3196">5.2. MODE2</a></li>
</ul>
</li>
<li><a href="#org502ebf5">6. バグが出てきたときの対処法（そのうち直します。）</a>
<ul>
<li><a href="#org2564e06">6.1. 起動した瞬間</a>
<ul>
<li><a href="#orgf9fedde">6.1.1. 一つのキーがずっと強制入力されてしまう。</a></li>
<li><a href="#org75f25bb">6.1.2. キーボード入力が完璧に受け付けなくなる。</a></li>
<li><a href="#org88d9052">6.1.3. 管理者権限が…ってでたら</a></li>
</ul>
</li>
<li><a href="#org925d0f0">6.2. 起動してから</a>
<ul>
<li><a href="#org712b708">6.2.1. 一つのキーが強制入力されてしまう現象がある。</a></li>
</ul>
</li>
<li><a href="#orgaa269e0">6.3. 終了後</a>
<ul>
<li><a href="#orga96bb8d">6.3.1. 入力ができなくなった、Ctrlが強制的に押されるようになった。</a></li>
</ul>
</li>
<li><a href="#orgaf49be8">6.4. その他</a></li>
</ul>
</li>
</ul>
</div>
</div>


<a id="orge4b9ebf"></a>

# 免責事項

公開しているソフトウェア、および同梱のファイルの使用、またはバグにより生じたいかなる損害に関しまして作者は一切責任を負いません。


<a id="org9b5ee37"></a>

# 特徴

-   このmousekeyはホームポジションでマウスカーソルを動かすソフトウェアである。
-   設定によってはメモ帳などで好きなように矢印を操作することができる。
-   動かすキーは自分で設定することができる。
-   プログラム実行中に3を押すと変な挙動をする。まるで世界のナベアツ（バグ）


<a id="org0a73d47"></a>

# 対象

-   Ubuntu16.04とUbuntu14.04とpi-topOSでは動くことを確認した。
-   おそらくLinux全般で動くと思われる。（動作報告をしてほしい。）
-   macOSやwindowsOSは対象では使えない。


<a id="org057518f"></a>

# 使用方法


<a id="org849bda8"></a>

## cmake、gitのインストール

cmakeをインストールしていない人はまずcmakeをインストールします。
以下コマンド
sudo apt install cmake
sudo apt install git


<a id="orga95e7f9"></a>

## 仮想環境を用いている場合

後で…


<a id="org2f42928"></a>

## プロジェクトのコンパイル

git clone &#x2026;(後で追記)
cd mousekey
cd exec
sh build.sh


<a id="org706eb82"></a>

## プロジェクトの実行

-   以下実行コマンド(管理者権限が必要です。)

sudo ./mousekey

-   attention::プログラムを実行したら、「a」が出てくるまで、キーボードを何も押さないでください。


<a id="orgef35f62"></a>

# デフォルトのキーバインド

設定はtest.confに記載。自由にカスタマイズできます。KEY\_●の●の部分を変えるだけです。


<a id="org2d406c8"></a>

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


<a id="org24c3196"></a>

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


<a id="org502ebf5"></a>

# バグが出てきたときの対処法（そのうち直します。）


<a id="org2564e06"></a>

## 起動した瞬間


<a id="orgf9fedde"></a>

### 一つのキーがずっと強制入力されてしまう。

-   aからzの間でキーを入力してみるとだいたい直る。
-   プログラムの終了キーを押す。デフォルトでは変換キー+Q
-   キーボードを取り外してみる。(はずせるなら)


<a id="org75f25bb"></a>

### キーボード入力が完璧に受け付けなくなる。

-   キーボードを取り外してみる。(はずせるなら)
-   マウスを使ってシャットダウンをする。(だいたいマウスも聞かない。)
-   電源ボタンを…


<a id="org88d9052"></a>

### 管理者権限が…ってでたら

-   管理者権限で実行してください。


<a id="org925d0f0"></a>

## 起動してから


<a id="org712b708"></a>

### 一つのキーが強制入力されてしまう現象がある。

-   aからzの間でキーを入力してみるとだいたい直る。
-   キーボードを取り外してみる。(はずせるなら)
-   マウスを使ってシャットダウンをする。(だいたいマウスも聞かない。)
-   電源ボタンを…
-   プログラムの終了キーを押す。デフォルトでは変換キー+Q


<a id="orgaa269e0"></a>

## 終了後


<a id="orga96bb8d"></a>

### 入力ができなくなった、Ctrlが強制的に押されるようになった。

-   TabとCtrlとshiftを同時に押す。
-   キーボードを取り外してみる。(はずせるなら)
-   待つ
-   マウスを使ってシャットダウンをする。(だいたいマウスも聞かない。)
-   電源ボタンを…


<a id="orgaf49be8"></a>

## その他

-   教えてください。

