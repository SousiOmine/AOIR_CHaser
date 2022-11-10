# プログラムの説明  
※この項目は現在記述中です  
# 目次
- [目次](#目次)  
- [共通コンポーネント](#共通コンポーネント)
  - [MapData配列](#mapdata配列)
  - [SETTING型](#setting型)
- [Client.c](#clientc)  
  - [main関数](#mainint-argc-char-argv)  

- [MapSystem.c](#mapsystemc)  
- [selectcmd.c](#selectcmdc)  
  - [selectcmd_rank関数](#selectcmd_rankint-usemapdata101101-int-usechinfo-int-mode-int-returncmd)  
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

# Client.c  
## main(int argc, char *argv[])  
全体の処理を総括しています。

# MapSystem.c  
## makeMapData(int EditMapData[101][101], int UseChInfo[], int returnNumber[], int interim, int mode, int count)  
mode引数のコマンドの実行結果をEditMapDataに反映させます。  
公式サンプルクライアントのRemakeReturnNumber19x19関数を代替します。  
interim引数は、未来予測時等の仮のMapData作成時に1を入れます。  

# selectcmd.c  
## selectcmd_rank(int UseMapData[101][101], int UseChInfo[], int mode, int returnCmd[])  
最適なコマンドを算出し、returnCmd引数に降順で格納する関数です。  
戻り値に最適なコマンドの番号をint型で返します。  
UseMapData引数には計算に使うMapData配列。  
UseChInfo引数には計算に使うChInfo配列。  
mode引数はGetReady時には1、Action時には2を入れます。  
returnCmd引数には最適なコマンドを格納する長さ50以上のint型配列を書いてください。  


# FileRead.h  
## read_settingfile(char *filePath)  
filePathの場所にある設定ファイルを読み込み、settingに書き込む関数です。  
戻り値はint型の0です。

## setting_reset()  
settingを初期値に戻す関数です。  