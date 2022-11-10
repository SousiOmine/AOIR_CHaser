#ifndef INCLUDED_SELECTCMD
#define INCLUDED_SELECTCMD
int selectcmd(int EditMapData[101][101], int UseChInfo[], int mode, int *returnCmd);  //最も適切なコマンドを求める関数
int selectcmd_rank(int UseMapData[101][101], int UseChInfo[], int mode, int returnCmd[]); //最も適切なコマンドを順位順の配列で求める関数
int emg_cmd(int UseMapData[101][101], int UseChInfo[], int mode, int returnCmd[]);  //アクションが受け付けられない際の代替コマンドを提供する関数
int PointCnt(int CmdNum, int depth ,int EditMapData[101][101], int UseChInfo[]); //コマンドの点数付けを行う関数
int move_tokuten(int *return_tokuten, int CmdNum, int EditMapData[101][101], int UseChInfo[]); //コマンドを実行した場合に得られる得点を求める関数
int tokuten(int x, int y, int UseMapData[101][101]);  //指定座標のアイテムの得点を求める関数
int hirou_pt(int *return_pt, int CmdNum);   //コマンド実行時の疲労を返す
int know_NewInfo(int *return_tokuten, int CmdNum, int UseMapData[101][101], int UseChInfo[]); //新しく知るマップキャラクタの数を求める
int koumyaku_pt(int *return_pt, int CmdNum, int UseMapData[101][101], int UseChInfo[]);
int NG_cmd(int CmdNum, int UseMapData[101][101], int UseChInfo[], int depth);    //条件下でコマンドを実行させない場合は1を返す
int anti_enemy_pt(int *return_pt, int CmdNum, int depth, int UseMapData[101][101], int UseChInfo[]);

#endif