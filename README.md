<!--?xml version="1.0" encoding="utf-8"?-->

<!-- 2017-09-07 木 01:42 -->

<meta http-equiv="Content-Type" content="text/html;charset=utf-8">

<meta name="viewport" content="width=device-width, initial-scale=1">

<title>mousekeyの使い方</title>

<meta name="generator" content="Org mode">

<meta name="author" content="taka">

<div id="content">
    mousekeyの使い方
    ============

    <div id="table-of-contents">
        Table of Contents
        -----------------

        <div id="text-table-of-contents">
            * 1. 免責事項
            * 2. 特徴
            * 3. 対象
            * 4. 使用方法

                * 4.1. cmake、gitのインストール
                * 4.2. 仮想環境を用いている場合
                * 4.3. プロジェクトのコンパイル
                * 4.4. プロジェクトの実行

            * 5. デフォルトのキーバインド

                * 5.1. MODE1
                * 5.2. MODE2

            * 6. バグが出てきたときの対処法（そのうち直します。）

                * 6.1. 起動した瞬間

                    * 6.1.1. 一つのキーがずっと強制入力されてしまう。
                    * 6.1.2. キーボード入力が完璧に受け付けなくなる。
                    * 6.1.3. 管理者権限が…ってでたら

                * 6.2. 起動してから

                    * 6.2.1. 一つのキーが強制入力されてしまう現象がある。

                * 6.3. 終了後

                    * 6.3.1. 入力ができなくなった、Ctrlが強制的に押されるようになった。

                * 6.4. その他

        </div>
    </div>

    <div id="outline-container-org95eed3d" class="outline-2">
        <span class="section-number-2">1</span> 免責事項
        --------------------------------------------

        <div class="outline-text-2" id="text-1">
            公開しているソフトウェア、および同梱のファイルの使用、またはバグにより生じたいかなる損害に関しまして作者は一切責任を負いません。
        </div>
    </div>

    <div id="outline-container-orgbfe1da0" class="outline-2">
        <span class="section-number-2">2</span> 特徴
        ------------------------------------------

        <div class="outline-text-2" id="text-2">
            * このmousekeyはホームポジションでマウスカーソルを動かすソフトウェアである。
            * 設定によってはメモ帳などで好きなように矢印を操作することができる。
            * 動かすキーは自分で設定することができる。
            * プログラム実行中に3を押すと変な挙動をする。まるで世界のナベアツ（バグ）
        </div>
    </div>

    <div id="outline-container-org156cc41" class="outline-2">
        <span class="section-number-2">3</span> 対象
        ------------------------------------------

        <div class="outline-text-2" id="text-3">
            * Ubuntu16.04とUbuntu14.04とpi-topOSでは動くことを確認した。
            * おそらくLinux全般で動くと思われる。（動作報告をしてほしい。）
            * macOSやwindowsOSは対象では使えない。
        </div>
    </div>

    <div id="outline-container-orgab01f67" class="outline-2">
        <span class="section-number-2">4</span> 使用方法
        --------------------------------------------

        <div class="outline-text-2" id="text-4"></div>

        <div id="outline-container-orgec93be6" class="outline-3">
            ### <span class="section-number-3">4.1</span> cmake、gitのインストール

            <div class="outline-text-3" id="text-4-1">
                cmakeをインストールしていない人はまずcmakeをインストールします。
                以下コマンド
                sudo apt install cmake
                sudo apt install git
            </div>
        </div>

        <div id="outline-container-org2aa7bea" class="outline-3">
            ### <span class="section-number-3">4.2</span> 仮想環境を用いている場合

            <div class="outline-text-3" id="text-4-2">
                後で…
            </div>
        </div>

        <div id="outline-container-orgbd0e49f" class="outline-3">
            ### <span class="section-number-3">4.3</span> プロジェクトのコンパイル

            <div class="outline-text-3" id="text-4-3">
                git clone …(後で追記)
                cd mousekey
                cd exec
                sh build.sh
            </div>
        </div>

        <div id="outline-container-org8e76e32" class="outline-3">
            ### <span class="section-number-3">4.4</span> プロジェクトの実行

            <div class="outline-text-3" id="text-4-4">
                * 以下実行コマンド(管理者権限が必要です。)

                sudo ./mousekey

                * attention::プログラムを実行したら、「a」が出てくるまで、キーボードを何も押さないでください。
            </div>
        </div>
    </div>

    <div id="outline-container-orgaa198dd" class="outline-2">
        <span class="section-number-2">5</span> デフォルトのキーバインド
        ----------------------------------------------------

        <div class="outline-text-2" id="text-5">
            設定はtest.confに記載。自由にカスタマイズできます。KEY_●の●の部分を変えるだけです。
        </div>

        <div id="outline-container-org53b5e97" class="outline-3">
            ### <span class="section-number-3">5.1</span> MODE1

            <div class="outline-text-3" id="text-5-1">
                <colgroup>
                <col class="org-left">

                <col class="org-left">
                </colgroup>
                col 1    | col 2                       
                -------- | ----------------------------
                変換+q     | プログラムの終了                    
                変換+f     | マウスを右にすすめる                  
                変換+b     | マウスを左にすすめる                  
                変換+p     | マウスを上にすすめる                  
                変換+n     | マウスを下にすすめる                  
                変換+a     | マウスのスピードを下げる                
                変換+e     | マウスのスピードを上げる                
                変換+sapce | 左クリック                       
                変換+l     | 右クリック                       
                変換+i     | ホイールを上に回す                   
                変換+k     | ホイールを下に回す                   
                変換+w     | ホイールクリック                    
                変換+u     | ブラウザの次へボタン                  
                変換+j     | ブラウザの戻るボタン                  
                変換+c     | MODE2にする。(モードを増やしたら他のモードになる)
            </div>
        </div>

        <div id="outline-container-orgb9753af" class="outline-3">
            ### <span class="section-number-3">5.2</span> MODE2

            <div class="outline-text-3" id="text-5-2">
                <colgroup>
                <col class="org-left">

                <col class="org-left">
                </colgroup>
                col 1 | col 2    
                ----- | ---------
                変換+h  | BackSpace
                変換+d  | Delete   
                変換+a  | Home     
                変換+e  | End      
                変換+m  | Enter    
                変換+n  | down     
                変換+f  | right    
                変換+p  | up       
                変換+b  | left     
                変換+c  | MODE1にする 
            </div>
        </div>
    </div>

    <div id="outline-container-org1a83450" class="outline-2">
        <span class="section-number-2">6</span> バグが出てきたときの対処法（そのうち直します。）
        ----------------------------------------------------------------

        <div class="outline-text-2" id="text-6"></div>

        <div id="outline-container-org44b3242" class="outline-3">
            ### <span class="section-number-3">6.1</span> 起動した瞬間

            <div class="outline-text-3" id="text-6-1"></div>

            <div id="outline-container-orgeaf97e0" class="outline-4">
                #### <span class="section-number-4">6.1.1</span> 一つのキーがずっと強制入力されてしまう。

                <div class="outline-text-4" id="text-6-1-1">
                    * aからzの間でキーを入力してみるとだいたい直る。
                    * プログラムの終了キーを押す。デフォルトでは変換キー+Q
                    * キーボードを取り外してみる。(はずせるなら)
                </div>
            </div>

            <div id="outline-container-orgde305ef" class="outline-4">
                #### <span class="section-number-4">6.1.2</span> キーボード入力が完璧に受け付けなくなる。

                <div class="outline-text-4" id="text-6-1-2">
                    * キーボードを取り外してみる。(はずせるなら)
                    * マウスを使ってシャットダウンをする。(だいたいマウスも聞かない。)
                    * 電源ボタンを…
                </div>
            </div>

            <div id="outline-container-org3872d52" class="outline-4">
                #### <span class="section-number-4">6.1.3</span> 管理者権限が…ってでたら

                <div class="outline-text-4" id="text-6-1-3">
                    * 管理者権限で実行してください。
                </div>
            </div>
        </div>

        <div id="outline-container-orgb0c062e" class="outline-3">
            ### <span class="section-number-3">6.2</span> 起動してから

            <div class="outline-text-3" id="text-6-2"></div>

            <div id="outline-container-org3db7d1d" class="outline-4">
                #### <span class="section-number-4">6.2.1</span> 一つのキーが強制入力されてしまう現象がある。

                <div class="outline-text-4" id="text-6-2-1">
                    * aからzの間でキーを入力してみるとだいたい直る。
                    * キーボードを取り外してみる。(はずせるなら)
                    * マウスを使ってシャットダウンをする。(だいたいマウスも聞かない。)
                    * 電源ボタンを…
                    * プログラムの終了キーを押す。デフォルトでは変換キー+Q
                </div>
            </div>
        </div>

        <div id="outline-container-org09fca3d" class="outline-3">
            ### <span class="section-number-3">6.3</span> 終了後

            <div class="outline-text-3" id="text-6-3"></div>

            <div id="outline-container-orgd6c51e7" class="outline-4">
                #### <span class="section-number-4">6.3.1</span> 入力ができなくなった、Ctrlが強制的に押されるようになった。

                <div class="outline-text-4" id="text-6-3-1">
                    * TabとCtrlとshiftを同時に押す。
                    * キーボードを取り外してみる。(はずせるなら)
                    * 待つ
                    * マウスを使ってシャットダウンをする。(だいたいマウスも聞かない。)
                    * 電源ボタンを…
                </div>
            </div>
        </div>

        <div id="outline-container-org7b3f162" class="outline-3">
            ### <span class="section-number-3">6.4</span> その他

            <div class="outline-text-3" id="text-6-4">
                * 教えてください。
            </div>
        </div>
    </div>
</div>

<div id="postamble" class="status">
    Author: taka

    Created: 2017-09-07 木 01:42

    [Validate](http://validator.w3.org/check?uri=referer)
</div>