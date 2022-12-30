# プログラムの説明  
※この項目は現在記述中です  
# 目次
- [目次](#目次)  
- [共通コンポーネント](#共通コンポーネント)
  - [MapData配列](#mapdata配列)
  - [SETTING型](#setting型)
  - [ChInfo配列](#chinfo配列)
- [Client.c](#clientc)  
  - [main関数](#mainint-argc-char-argv)  
  - [senc_cmd関数](#send_cmdchar-command-char-param-char-returncode)
- [MapSystem.c](#mapsystemc)  
  - [makeMapData関数](#makemapdataint-editmapdata101101-int-usechinfo-int-returnnumber-int-interim-int-mode-int-count)
  - [drawMapData関数](#drawmapdataint-editmapdata101101-int-usechinfo)
  - [writeMapData関数](#writemapdataint-interim-int-x1-int-y1-int-x2-int-y2-int-returnnumber-int-editmapdata101101)
  - [jyougai関数](#jyougaiint-x1-int-y1-int-x2-int-y2-int-mapdata101101-int-usechinfo)
  - [fillMapData関数](#fillmapdataint-x1-int-y1-int-x2-int-y2-int-editmapdata101101-int-ch_num)
- [selectcmd.c](#selectcmdc)  
  - [selectcmd_rank関数](#selectcmd_rankint-usemapdata101101-int-usechinfo-int-mode-int-returncmd) 
  - [PointCnt関数](#pointcntint-cmdnum-int-depth-int-editmapdata101101-int-usechinfo) 
- [FileRead.h](#filereadh)  
  - [read_settingfile関数](#read_settingfilechar-filepath)  
  - [setting_reset関数](#setting_reset)


# 共通コンポーネント  
## MapData配列  
サンプルクライアントのマップ保持配列「HoseiReturnNumber」を代替する配列です。  
自キャラの位置に関係なくマップ全体を記録することができます。  
大きさは101*101になっています。  
１つめの添字はマップ左を0としたx座標、２つめの添字はマップ上を0とし下に行くほど数字が大きくなるy座標を格納します。  
## SETTING型  
設定を記憶する構造体で、include/setting.hにて定義されています。  
Client.cの最初でsettingとして宣言され、read_settingfile関数で設定ファイルを読み込みsettingに登録されます。  
## ChInfo配列  
自キャラクタの情報を格納する配列で長さは10。  
要素1には自キャラクタの初期位置を0としたときのMapDataにおけるX座標を、要素2には同じくY座標を格納しています。  
要素3には自キャラクタの番号(1000～8000)を格納しています。この処理はMapSystem.cのgrコマンド実行時の処理に書かれています。  

# Client.c  
大まかな処理の流れとしては2022年度サンプルプログラム(CHaserOnlineClient2022public001.c)と変わりません。  
サンプルプログラムの文字コードはShift-JISでしたがClient.cではUTF-8となっています。  
## main(int argc, char *argv[])  
全体の処理を総括しています。  
ウェイト時間、自動終了制限回数、マップ表示モードを引数で指定できるような記述がありますが現時点で対応していません。  
## send_cmd(char *command, char *param, char *returnCode)  
コマンドの送信を行います。  
サンプルプログラムと殆ど変化はありませんが、サンプルプログラムにてWebBuf配列とSendBuf配列宣言部分でコンパイル時に発生する警告を修正してあります。  
またエラー表示にサンプルプログラムとの若干の差異があります。  

# MapSystem.c  
## makeMapData(int EditMapData[101][101], int UseChInfo[], int returnNumber[], int interim, int mode, int count)  
mode引数のコマンドの実行結果をEditMapDataに反映させます。  
公式サンプルクライアントのRemakeReturnNumber19x19関数を代替します。  
interim引数は、シュミレート時等の仮のMapData作成時に1を入れます。1にすることでmakeMapData内でjyougai関数が呼ばれなくなり処理時間が短くなります。  
## drawMapData(int EditMapData[101][101], int UseChInfo[])  
EditMapDataとUseChInfoの情報を元にマップを標準出力に描写します。  
戻り値はint型の0です。    
## writeMapData(int interim, int x1, int y1, int x2, int y2, int returnNumber[], int EditMapData[101][101])  
returnNumberの値をEditMapDataの指定範囲に書き込みます。  
x1,y1に左上の座標を、x2,y2に右下の座標を入れてください。  
interimはmakeMapData同様仮の情報を扱う際に1を入れますが、この際指定範囲内にまだ一度も情報を取得していないマス(-2)があった場合、既知であるはずの場所(-9999)として書き込まれます。情報の記録をシュミレートするのに役立ちます。  
戻り値はint型の0です。  
## jyougai(int *x1, int *y1, int *x2, int *y2, int MapData[101][101], int UseChInfo[])  
場外を算出し書き込み、ポインタ引数に場外範囲を格納します。  
## fillMapData(int x1, int y1, int x2, int y2, int EditMapData[101][101], int ch_num)  
指定した範囲をch_numの値で埋めます。  
# selectcmd.c  
## selectcmd_rank(int UseMapData[101][101], int UseChInfo[], int mode, int returnCmd[])  
最適なコマンドを算出し、returnCmd引数に降順で格納する関数です。  
戻り値に最適なコマンドの番号をint型で返します。  
UseMapData引数には計算に使うMapData配列。  
UseChInfo引数には計算に使うChInfo配列。  
mode引数はGetReady時には1、Action時には2を入れます。  
returnCmd引数には最適なコマンドを格納する長さ50以上のint型配列を書いてください。  
## PointCnt(int CmdNum, int depth, int EditMapData[101][101], int UseChInfo[])  
CmdNumのコマンドを実行した際の結果に得点付けを行います。


# FileRead.h  
## read_settingfile(char *filePath)  
filePathの場所にある設定ファイルを読み込み、settingに書き込む関数です。  
戻り値はint型の0です。

## setting_reset()  
settingの初期値を設定する関数です。  