<!--?xml version="1.0" encoding="utf-8"?-->

<!-- 2017-09-09 土 23:56 -->

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

        </div>
    </div>

    <div id="outline-container-orgd04d12b" class="outline-2">
        <span class="section-number-2">1</span> 免責事項
        --------------------------------------------

        <div class="outline-text-2" id="text-1">
            公開しているソフトウェア、および同梱のファイルの使用、またはバグにより生じたいかなる損害に関しまして作者は一切責任を負いません。
        </div>
    </div>

    <div id="outline-container-org541aac1" class="outline-2">
        <span class="section-number-2">2</span> 特徴
        ------------------------------------------

        <div class="outline-text-2" id="text-2">
            * このmousekeyはホームポジションでマウスカーソルを動かすソフトウェアである。
            * マウスを動かすキーボードのキーは自分で設定することができる。
        </div>
    </div>

    <div id="outline-container-org659d935" class="outline-2">
        <span class="section-number-2">3</span> 対象
        ------------------------------------------

        <div class="outline-text-2" id="text-3">
            * Ubuntu16.04とUbuntu14.04とpi-topOSでは動くことを確認した。
            * おそらくLinux全般で動くと思われる。（動作報告をしてほしい。）
            * macOSやwindowsOSは対象ではない。
        </div>
    </div>

    <div id="outline-container-orge92579e" class="outline-2">
        <span class="section-number-2">4</span> 使用方法
        --------------------------------------------

        <div class="outline-text-2" id="text-4"></div>

        <div id="outline-container-orgdc5e2e9" class="outline-3">
            ### <span class="section-number-3">4.1</span> cmake、gitのインストール

            <div class="outline-text-3" id="text-4-1">
                cmakeをインストールしていない人はまずcmakeをインストールします。
                以下コマンド
                sudo apt install cmake
                sudo apt install git
            </div>
        </div>

        <div id="outline-container-orgc98611f" class="outline-3">
            ### <span class="section-number-3">4.2</span> 仮想環境を用いている場合

            <div class="outline-text-3" id="text-4-2">
                マウス統合を解除することによって使えるようになります。
            </div>
        </div>

        <div id="outline-container-org4ce0b83" class="outline-3">
            ### <span class="section-number-3">4.3</span> プロジェクトのコンパイル

            <div class="outline-text-3" id="text-4-3">
                git clone https://bitbucket.org/hemuhemu33/mousekey.git
                cd mousekey
                cd exec
                sh build.sh
            </div>
        </div>

        <div id="outline-container-org1152c53" class="outline-3">
            ### <span class="section-number-3">4.4</span> プロジェクトの実行

            <div class="outline-text-3" id="text-4-4">
                * 以下実行コマンド(管理者権限が必要)

                sudo ./mousekey
                バックグラウンドで動かす場合、
                sudo ./mousekey &
            </div>
        </div>
    </div>

    <div id="outline-container-org70b6f3e" class="outline-2">
        <span class="section-number-2">5</span> デフォルトのキーバインド
        ----------------------------------------------------

        <div class="outline-text-2" id="text-5">
            設定はtest.confに記載。自由にカスタマイズできます。KEY_●の●の部分を変えるだけです。
        </div>

        <div id="outline-container-org9bfe43d" class="outline-3">
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

        <div id="outline-container-org4cf74ea" class="outline-3">
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
</div>

<div id="postamble" class="status">
    Author: taka

    Created: 2017-09-09 土 23:56

    [Validate](http://validator.w3.org/check?uri=referer)
</div>
