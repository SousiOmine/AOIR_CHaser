#ifndef INCLUDED_MAPSYSTEM
#define INCLUDED_MAPSYSTEM

int makeMapData(int EditMapData[101][101], int UseChInfo[], int returnNumber[], int interim, int mode, int count);
int drawMapData(int EditMapData[101][101], int UseChInfo[]);
int writeMapData(int interim, int x1, int y1, int x2, int y2, int returnNumber[], int EditMapData[101][101]);
int jyougai(int *x1, int *y1, int *x2, int *y2, int MapData[101][101], int UseChInfo[]);    //場外の境界を求める関数
void fillMapData(int x1, int y1, int x2, int y2, int EditMapData[101][101], int ch_num);  //選択範囲内のマップをch_numで埋める
int if_warp(int *cx, int *cy, int EditMapData[101][101]); //makeMapData関数内にて使う、ワープマスを踏んだかを検知し処理を行う
int can_crush(int ch_num);    //引数で指定した番号のキャラクタは砕けるかどうか判定する、砕ければ1、砕けなければ0

#endif