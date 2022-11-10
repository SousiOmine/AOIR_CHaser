#include "include/selectcmd.h"
#include "include/MapSystem.h"
#include "include/setting.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

extern SETTING setting;

int selectcmd_rank(int UseMapData[101][101], int UseChInfo[], int mode, int returnCmd[])
{
    int start_clock;
    start_clock = clock(); //実行クロックの計測を行う

    int amount_comp[3] = {-1, 5, 36};
    int cmdPt[100], cmdRank[100], bestRoute[100][10] = {0};
    int i, j, temp, temp2, temp3;
    int kari1MapData[101][101], kari2MapData[101][101], kari3MapData[101][101], kari4MapData[101][101], kari5MapData[101][101], kari6MapData[101][101];
    int kari1ChInfo[10], kari2ChInfo[10], kari3ChInfo[10], kari4ChInfo[10], kari5ChInfo[10], kari6ChInfo[10];
    int turn1, turn2, turn3, turn4, turn5, turn6;
    int turn2_mode, turn3_mode, turn4_mode, turn5_mode, turn6_mode;
    int hikaku, hikaku2, hikaku3, hikaku4, hikaku5, hikaku6;
    int kariReturnNumber[9] = {0};
    int cmd[3][100];

    //#pragma omp threadprivate(turn2, turn3, turn4, turn5, turn6)
    //#pragma omp threadprivate(kari1MapData, kari2MapData, kari3MapData, kari4MapData, kari5MapData, kari6MapData)
    //#pragma omp threadprivate(kari1ChInfo, kari2ChInfo, kari3ChInfo, kari4ChInfo, kari5ChInfo, kari6ChInfo)
    //#pragma omp threadprivate(hikaku, hikaku2, hikaku3, hikaku4, hikaku5, hikaku6)

    // mode1(GetReadyMode)で使用できるコマンドをここにかく

    cmd[1][0] = 4;
    cmd[1][1] = 1;
    cmd[1][2] = 3;
    cmd[1][3] = 5;
    cmd[1][4] = 7;

    // mode2(Action)で使用できるコマンドをここに書く
    cmd[2][0] = 1;
    cmd[2][1] = 3;
    cmd[2][2] = 5;
    cmd[2][3] = 7;
    cmd[2][4] = 100;
    cmd[2][5] = 101;
    cmd[2][6] = 102;
    cmd[2][7] = 103;
    cmd[2][8] = 120;
    cmd[2][9] = 121;
    cmd[2][10] = 122;
    cmd[2][11] = 123;
    cmd[2][12] = 110;
    cmd[2][13] = 111;
    cmd[2][14] = 112;
    cmd[2][15] = 113;
    cmd[2][16] = 32;
    cmd[2][17] = 38;
    cmd[2][18] = 30;
    cmd[2][19] = 36;
    cmd[2][20] = 11;
    cmd[2][21] = 13;
    cmd[2][22] = 15;
    cmd[2][23] = 17;
    cmd[2][24] = 10;
    cmd[2][25] = 12;
    cmd[2][26] = 16;
    cmd[2][27] = 18;
    cmd[2][28] = 41;
    cmd[2][29] = 43;
    cmd[2][30] = 45;
    cmd[2][31] = 46;
    cmd[2][32] = 144;
    cmd[2][33] = 145;
    cmd[2][34] = 146;
    cmd[2][35] = 147;

    for (i = 0; i < amount_comp[mode]; i++)
    {
        cmdPt[i] = -999999999;
        cmdRank[i] = i;
        returnCmd[i] = cmd[mode][i];
    }

    if (mode == 1) //未来予測する際に、GetReadyとActionでは実行可能なコマンドが異なるので注意
    {
        turn2_mode = 2;
        turn3_mode = 1;
        turn4_mode = 2;
        turn5_mode = 1;
        turn6_mode = 2;
    }

    else if (mode == 2)
    {
        turn2_mode = 1;
        turn3_mode = 2;
        turn4_mode = 1;
        turn5_mode = 2;
        turn6_mode = 1;
    }

    //#pragma omp parallel for
    for (turn1 = 0; turn1 < amount_comp[mode]; turn1++)
    {
        // printf("%d\n", cmd[mode][turn1]);
        memcpy(kari1MapData, UseMapData, sizeof(kari1MapData));
        memcpy(kari1ChInfo, UseChInfo, sizeof(kari1ChInfo));
        hikaku = PointCnt(cmd[mode][turn1], 1, kari1MapData, kari1ChInfo);
        makeMapData(kari1MapData, kari1ChInfo, kariReturnNumber, 1, cmd[mode][turn1], 9);
        for (turn2 = 0; turn2 < amount_comp[turn2_mode]; turn2++)
        {
            // printf("\t%d\n", cmd[turn2_mode][turn2]);
            memcpy(kari2MapData, kari1MapData, sizeof(kari2MapData));
            memcpy(kari2ChInfo, kari1ChInfo, sizeof(kari2ChInfo));
            hikaku2 = PointCnt(cmd[turn2_mode][turn2], 2, kari2MapData, kari2ChInfo);
            makeMapData(kari2MapData, kari2ChInfo, kariReturnNumber, 1, cmd[turn2_mode][turn2], 9);
            for (turn3 = 0; turn3 < amount_comp[turn3_mode]; turn3++)
            {
                // printf("\t\t%d\n", cmd[turn3_mode][turn3]);
                memcpy(kari3MapData, kari2MapData, sizeof(kari3MapData));
                memcpy(kari3ChInfo, kari2ChInfo, sizeof(kari3ChInfo));
                hikaku3 = PointCnt(cmd[turn3_mode][turn3], 3, kari3MapData, kari3ChInfo);
                makeMapData(kari3MapData, kari3ChInfo, kariReturnNumber, 1, cmd[turn3_mode][turn3], 9);
                if ((hikaku * 10 + hikaku2 * 9 + hikaku3 * 8) > -1000000)
                {
                    for (turn4 = 0; turn4 < amount_comp[turn4_mode]; turn4++)
                    {
                        // printf("\t\t\t%d\n", cmd[turn4_mode][turn4]);
                        memcpy(kari4MapData, kari3MapData, sizeof(kari4MapData));
                        memcpy(kari4ChInfo, kari3ChInfo, sizeof(kari4ChInfo));
                        hikaku4 = PointCnt(cmd[turn4_mode][turn4], 4, kari4MapData, kari4ChInfo);
                        makeMapData(kari4MapData, kari4ChInfo, kariReturnNumber, 1, cmd[turn4_mode][turn4], 9);
                        if ((hikaku * 10 + hikaku2 * 9 + hikaku3 * 8 + hikaku4 * 7) > -300000)
                        {
                            for (turn5 = 0; turn5 < amount_comp[turn4_mode]; turn5++)
                            {
                                // printf("\t\t\t\t%d\n", cmd[turn5_mode][turn5]);
                                memcpy(kari5MapData, kari4MapData, sizeof(kari5MapData));
                                memcpy(kari5ChInfo, kari4ChInfo, sizeof(kari5ChInfo));
                                hikaku5 = PointCnt(cmd[turn5_mode][turn5], 5, kari5MapData, kari5ChInfo);
                                makeMapData(kari5MapData, kari5ChInfo, kariReturnNumber, 1, cmd[turn5_mode][turn5], 9);
                                if ((hikaku * 10 + hikaku2 * 9 + hikaku3 * 8 + hikaku4 * 7 + hikaku5 * 6) > -300000)
                                {
                                    for (turn6 = 0; turn6 < amount_comp[turn6_mode]; turn6++)
                                    {
                                        // printf("\t\t\t\t\t%d\n", cmd[turn6_mode][turn6]);
                                        memcpy(kari6MapData, kari5MapData, sizeof(kari6MapData));
                                        memcpy(kari6ChInfo, kari5ChInfo, sizeof(kari6ChInfo));
                                        hikaku6 = PointCnt(cmd[turn6_mode][turn6], 6, kari6MapData, kari6ChInfo);
                                        if (((hikaku * 10) + (hikaku2 * 9) + (hikaku3 * 8) + (hikaku4 * 7) + (hikaku5 * 6) + (hikaku6 * 5)) >= cmdPt[turn1])
                                        {
                                            cmdPt[turn1] = (hikaku * 10) + (hikaku2 * 9) + (hikaku3 * 8) + (hikaku4 * 7) + (hikaku5 * 6) + (hikaku6 * 5);
                                            bestRoute[turn1][1] = cmd[mode][turn1];
                                            bestRoute[turn1][2] = cmd[turn2_mode][turn2];
                                            bestRoute[turn1][3] = cmd[turn3_mode][turn3];
                                            bestRoute[turn1][4] = cmd[turn4_mode][turn4];
                                            bestRoute[turn1][5] = cmd[turn5_mode][turn5];
                                            bestRoute[turn1][6] = cmd[turn6_mode][turn6];
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < amount_comp[mode]; i++) // returnCmdを点数の高い順に並べ替え
    {
        for (j = i + 1; j < amount_comp[mode]; j++)
        {
            if (cmdPt[i] < cmdPt[j])
            {
                temp = cmdPt[i];
                temp2 = cmdRank[i];
                temp3 = returnCmd[i];
                cmdPt[i] = cmdPt[j];
                cmdRank[i] = cmdRank[j];
                returnCmd[i] = returnCmd[j];
                cmdPt[j] = temp;
                cmdRank[j] = temp2;
                returnCmd[j] = temp3;
            }
        }
    }

    printf("最適なコマンドは%d→%d→%d→%d→%d→%d、得点は%dでした\n", bestRoute[cmdRank[0]][1], bestRoute[cmdRank[0]][2], bestRoute[cmdRank[0]][3], bestRoute[cmdRank[0]][4], bestRoute[cmdRank[0]][5], bestRoute[cmdRank[0]][6], cmdPt[0]);
    printf("CPUはselectcmd_rankを%f秒かけて実行しました\n", (double)(clock() - start_clock) / CLOCKS_PER_SEC);

    return returnCmd[0];
}

int PointCnt(int CmdNum, int depth, int EditMapData[101][101], int UseChInfo[])
{
    if (NG_cmd(CmdNum, EditMapData, UseChInfo, depth))
    {
        return -99999999;
    }

    int pt = 0, tokuten = 0, tanchi = 0, hirou = 0, koumyaku = 0, anti_enemy = 0;
    move_tokuten(&tokuten, CmdNum, EditMapData, UseChInfo);
    know_NewInfo(&tanchi, CmdNum, EditMapData, UseChInfo);
    hirou_pt(&hirou, CmdNum);
    koumyaku_pt(&koumyaku, CmdNum, EditMapData, UseChInfo);
    anti_enemy_pt(&anti_enemy, CmdNum, depth, EditMapData, UseChInfo);

    pt = (tokuten * 110) - (hirou * 110) + (anti_enemy * 100) + (tanchi * 1000) + (koumyaku * 120);

    return pt;
}

int move_tokuten(int *return_tokuten, int CmdNum, int EditMapData[101][101], int UseChInfo[])
{
    int getx = UseChInfo[0], gety = UseChInfo[1]; //得点を調べたい座標を格納

    switch (CmdNum)
    {
    case 1: //上
    case 17:
    case 102:
    case 112:
    case 131:
    case 41:
        gety = UseChInfo[1] - 1;
        break;

    case 3: //左
    case 15:
    case 101:
    case 111:
    case 133:
    case 43:
        getx = UseChInfo[0] - 1;
        break;

    case 5: //右
    case 13:
    case 100:
    case 110:
    case 132:
    case 45:
        getx = UseChInfo[0] + 1;
        break;

    case 7: //下
    case 11:
    case 103:
    case 113:
    case 130:
    case 47:
        gety = UseChInfo[1] + 1;
        break;

    case 12: //左下
    case 134:
    case 147: //(ステップアップヒントには左上と記載があったけどおそらく記入みす)
        getx = UseChInfo[0] - 1;
        gety = UseChInfo[1] + 1;
        break;

    case 10: //右下
    case 135:
    case 145:
        getx = UseChInfo[0] + 1;
        gety = UseChInfo[1] + 1;
        break;

    case 18: //左上
    case 136:
    case 146:
        getx = UseChInfo[0] - 1;
        gety = UseChInfo[1] - 1;
        break;

    case 16: //右上
    case 137:
    case 144:
        getx = UseChInfo[0] + 1;
        gety = UseChInfo[1] - 1;
        break;

    case 32: // keiru
        getx = UseChInfo[0] + 1;
        gety = UseChInfo[1] - 2;
        break;

    case 38: // keird
        getx = UseChInfo[0] + 1;
        gety = UseChInfo[1] + 2;
        break;

    case 30:
        getx = UseChInfo[0] - 1;
        gety = UseChInfo[1] - 2;
        break;

    case 36:
        getx = UseChInfo[0] - 1;
        gety = UseChInfo[1] + 2;
        break;

    default:
        break;
    }

    *return_tokuten = tokuten(getx, gety, EditMapData);

    return *return_tokuten;
}

int tokuten(int x, int y, int UseMapData[101][101])
{
    int itemcode, tokuten;
    itemcode = UseMapData[x][y];

    switch (itemcode)
    {

    case -9999: //既知であるはずの場所
        tokuten = 10;
        break;
    case -2: //未知の場所
        tokuten = -5000;
        break;
    case -1: //場外
        tokuten = -500;
        break;

    case 0: //穴 以下ステップアップヒント記載の番号準拠
        tokuten = -20;
        break;
    case 1:
        tokuten = 50;
        break;
    case 2:
        tokuten = 10;
        break;
    case 3:
        tokuten = 30;
        break;
    case 4:
        tokuten = -600;
        break;
    case 5:
        tokuten = 125;
        break;
    case 6:
        tokuten = 150;
        break;
    case 7:
        tokuten = 175;
        break;
    case 8:
        tokuten = 200;
        break;
    case 20:
    case 21:
    case 22:
    case 23:
        tokuten = 5;
        break;
    case 9:
        tokuten = 100;
        break;

    case 30: //ステップアップヒントにも載っていない未知のキャラクタ、数字は仮
    case 31:
    case 32:
    case 33:
        tokuten = 5;
        break;

    case 40:
    case 41:
    case 42:
    case 43:
    case 50:
    case 51:
    case 52:
    case 53:
        tokuten = -10;
        break;
    case 12:
        tokuten = -300;
        break;
    case 60:
    case 61:
    case 62:
    case 63:
        tokuten = 5;
        break;
    case 1000:
    case 2000:
    case 3000:
    case 4000:
    case 5000:
    case 6000:
    case 7000:
    case 8000:
        tokuten = -2000;
        break;

    default:
        tokuten = -10000;
        break;
    }

    return tokuten;
}

int hirou_pt(int *return_pt, int CmdNum)
{
    int pt = 0;
    switch (CmdNum)
    {
    case 1: // walk系
    case 3:
    case 5:
    case 7:
        pt = 1;
        break;

    case 11: // put2&walk系
    case 13:
    case 15:
    case 17:
        pt = 10;
        break;
    case 10:
    case 12:
    case 16:
    case 18:
        pt = 1000;
        break;

    case 32: // kei系
    case 38:
    case 30:
    case 36:
        pt = 30;
        break;

    case 120: // put0系
    case 121:
    case 122:
    case 123:
        pt = 1;
        break;

    case 130: // put0&walk
    case 131:
    case 132:
    case 133:
        pt = 20;
        break;
    case 134:
    case 135:
    case 136:
    case 137:
        pt = 200;
        break;

    case 41: // dig系
    case 47:
    case 43:
    case 45:
    case 144:
    case 145:
    case 146:
    case 147:
        pt = 20;
        break;

    case 100: // put3系
    case 101:
    case 102:
    case 103:
    case 110:
    case 111:
    case 112:
    case 113:
        pt = 30;
        break;

    default:
        pt = 0;
        break;
    }

    *return_pt = pt;
    return *return_pt;
}

int know_NewInfo(int *return_tokuten, int CmdNum, int UseMapData[101][101], int UseChInfo[])
{
    int kariMapData[101][101], kariChInfo[10];
    int kariReturnNumber[9] = {0};
    int i;
    int new_cnt = 0; //新しく見つかったキャラの数を格納する

    memcpy(kariMapData, UseMapData, sizeof(kariMapData));
    memcpy(kariChInfo, UseChInfo, sizeof(kariChInfo));

    makeMapData(kariMapData, kariChInfo, kariReturnNumber, 1, CmdNum, 9);

    for (i = 0; i < 9; i++) //新規に判明する座標の数をカウント(詳細はwriteMapData関数を参照)
    {
        if (kariReturnNumber[i] == 10000)
            new_cnt++;
    }

    *return_tokuten = new_cnt;

    return *return_tokuten;
}

int koumyaku_pt(int *return_pt, int CmdNum, int UseMapData[101][101], int UseChInfo[])
{
    int kariMapData[101][101];
    int cx, cy;
    cx = UseChInfo[0];
    cy = UseChInfo[1];
    if (CmdNum == 100 && UseMapData[cx][cy - 1] == 4)
    {
        if (UseMapData[cx + 1][cy - 1] == 4 && UseMapData[cx - 1][cy - 1] == 4 && UseMapData[cx + 1][cy - 2] == -2)
            *return_pt = 100;
    }
    else if (CmdNum == 101 && UseMapData[cx][cy + 1] == 4)
    {
        if (UseMapData[cx + 1][cy + 1] == 4 && UseMapData[cx - 1][cy + 1] == 4 && UseMapData[cx + 1][cy + 2] == -2)
            *return_pt = 100;
    }
    else if (CmdNum == 102 && UseMapData[cx - 1][cy] == 4)
    {
        if (UseMapData[cx - 1][cy + 1] == 4 && UseMapData[cx - 1][cy - 1] == 4 && UseMapData[cx - 2][cy - 1] == -2)
            *return_pt = 100;
    }
    else if (CmdNum == 103 && UseMapData[cx + 1][cy] == 4)
    {
        if (UseMapData[cx + 1][cy + 1] == 4 && UseMapData[cx + 1][cy - 1] == 4 && UseMapData[cx + 2][cy + 1] == -2)
            *return_pt = 100;
    }

    return *return_pt;
}

int NG_cmd(int CmdNum, int UseMapData[101][101], int UseChInfo[], int depth)
{
    int cx, cy, NG = 0;
    cx = UseChInfo[0];
    cy = UseChInfo[1];

    switch (CmdNum)
    {
    case 100: // pu3su
        if (UseMapData[cx][cy - 2] == -1 || UseMapData[cx][cy - 1] == 12)
            NG = 1;
        break;

    case 101: // pd3sd
        if (UseMapData[cx][cy + 2] == -1 || UseMapData[cx][cy + 1] == 12)
            NG = 1;
        break;

    case 102: // pl3sl
        if (UseMapData[cx - 2][cy] == -1 || UseMapData[cx - 1][cy] == 12)
            NG = 1;
        break;

    case 103: // pr3sr
        if (UseMapData[cx + 2][cy] == -1 || UseMapData[cx + 1][cy] == 12)
            NG = 1;
        break;

    case 4:
        if (depth >= 3)
            NG = 1;
        break;

    default:
        break;
    }

    return NG;
}

int anti_enemy_pt(int *return_pt, int CmdNum, int depth, int UseMapData[101][101], int UseChInfo[])
{
    if (depth == 1)
    {
        switch (CmdNum)
        {
        case 10:
            if (UseMapData[UseChInfo[0] - 1][UseChInfo[1] - 1] >= 1000 && UseMapData[UseChInfo[0] - 1][UseChInfo[1] - 1] != UseChInfo[2])
                *return_pt = 8000;
            break;
        case 11:
            if (UseMapData[UseChInfo[0]][UseChInfo[1] - 1] >= 1000 && UseMapData[UseChInfo[0]][UseChInfo[1] - 1] != UseChInfo[2])
                *return_pt = 8000;
            break;
        case 12:
            if (UseMapData[UseChInfo[0] + 1][UseChInfo[1] - 1] >= 1000 && UseMapData[UseChInfo[0] + 1][UseChInfo[1] - 1] != UseChInfo[2])
                *return_pt = 8000;
            break;
        case 13:
            if (UseMapData[UseChInfo[0] - 1][UseChInfo[1]] >= 1000 && UseMapData[UseChInfo[0] - 1][UseChInfo[1]] != UseChInfo[2])
                *return_pt = 8000;
            break;
        case 15:
            if (UseMapData[UseChInfo[0] + 1][UseChInfo[1]] >= 1000 && UseMapData[UseChInfo[0] + 1][UseChInfo[1]] != UseChInfo[2])
                *return_pt = 8000;
            break;
        case 16:
            if (UseMapData[UseChInfo[0] - 1][UseChInfo[1] + 1] >= 1000 && UseMapData[UseChInfo[0] - 1][UseChInfo[1] + 1] != UseChInfo[2])
                *return_pt = 8000;
            break;
        case 17:
            if (UseMapData[UseChInfo[0]][UseChInfo[1] + 1] >= 1000 && UseMapData[UseChInfo[0]][UseChInfo[1] + 1] != UseChInfo[2])
                *return_pt = 8000;
            break;
        case 18:
            if (UseMapData[UseChInfo[0] + 1][UseChInfo[1] + 1] >= 1000 && UseMapData[UseChInfo[0] + 1][UseChInfo[1] + 1] != UseChInfo[2])
                *return_pt = 8000;
            break;

        default:
            break;
        }
    }

    return *return_pt;
}