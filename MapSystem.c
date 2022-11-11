#include "include/MapSystem.h"
#include "include/setting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern SETTING setting;

int makeMapData(int EditMapData[101][101], int UseChInfo[], int returnNumber[], int interim, int mode, int count) //渡されたMapData配列を構成＆更新する、interimは扱うデータが仮のものであるか
{
    int sx = 0, sy = 0; //処理X、処理Yという意味
    int cx, cy;         //自キャラの座標を格納する
    int i;

    cx = UseChInfo[0];
    cy = UseChInfo[1];

    switch (mode)
    {
    case 4: //その場でgr
        switch (count)
        {
        case 9: //自キャラを中心に記録
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            if (returnNumber[4] >= 1000)
                UseChInfo[2] = returnNumber[4]; //自キャラの番号を記録
            break;
        case 6:
            break;

        case -1:
            fillMapData(cx - 1, cy - 1, cx + 1, cy + 1, EditMapData, -1); //周囲９マスを場外で埋める
            break;
        default:
            break;
        }

        break;

    case 1: //上に移動
        cy--;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        case 6:
            writeMapData(interim, cx - 1, cy, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        case -1:
            fillMapData(cx - 1, cy - 1, cx + 1, cy + 1, EditMapData, -1);
            break;

        default:
            break;
        }

        break;

    case 3: //左に移動
        cx--;

        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        case 6:
            writeMapData(interim, cx, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        case -1:
            fillMapData(cx - 1, cy - 1, cx + 1, cy + 1, EditMapData, -1);
            break;

        default:
            break;
        }

        break;

    case 5: //右に移動(wr, grr)
        cx++;

        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        case 6:
            writeMapData(interim, cx - 1, cy - 1, cx, cy + 1, returnNumber, EditMapData);
            break;

        case -1:
            fillMapData(cx - 1, cy - 1, cx + 1, cy + 1, EditMapData, -1);
            break;

        default:
            break;
        }

        break;

    case 7: //下に移動(wd)
        cy++;

        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        case 6:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy, returnNumber, EditMapData);
            break;

        case -1:
            fillMapData(cx - 1, cy - 1, cx + 1, cy + 1, EditMapData, -1);
            break;

        default:
            break;
        }

        break;

    case 10: // plu2wrd
        if (EditMapData[cx - 1][cy - 1] < 1000)
            EditMapData[cx - 1][cy - 1] = 2;

        cx++;
        cy++;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        default:
            EditMapData[cx - 1][cy - 1] = 0;
            break;
        }

        break;

    case 11: // pu2wd
        if (EditMapData[cx][cy - 1] < 1000)
            EditMapData[cx][cy - 1] = 2;

        cy++;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        case 6:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy, returnNumber, EditMapData);
            break;

        case -1:
            fillMapData(cx - 1, cy - 1, cx + 1, cy + 1, EditMapData, -1);
            break;

        default:
            break;
        }

        break;

    case 12: // pru2wld
        if (EditMapData[cx + 1][cy - 1] < 1000)
            EditMapData[cx + 1][cy - 1] = 2;

        cx--;
        cy++;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        default:
            EditMapData[cx + 1][cy - 1] = 0;
            break;
        }

        break;

    case 13: // pl2wr
        if (EditMapData[cx - 1][cy] < 1000)
            EditMapData[cx - 1][cy] = 2;
        cx++;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        case 6:
            writeMapData(interim, cx - 1, cy - 1, cx, cy + 1, returnNumber, EditMapData);
            break;

        case -1:
            fillMapData(cx - 1, cy - 1, cx + 1, cy + 1, EditMapData, -1);
            break;

        default:
            break;
        }

        break;

    case 15: // pr2wl
        if (EditMapData[cx + 1][cy] < 1000)
            EditMapData[cx + 1][cy] = 2;
        cx--;

        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        case 6:
            writeMapData(interim, cx, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        case -1:
            fillMapData(cx - 1, cy - 1, cx + 1, cy + 1, EditMapData, -1);
            break;

        default:
            break;
        }

        break;

    case 16: // pld2wru
        if (EditMapData[cx - 1][cy + 1] < 1000)
            EditMapData[cx - 1][cy + 1] = 2;

        cx++;
        cy--;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        default:
            EditMapData[cx - 1][cy + 1] = 0;
            break;
        }

        break;

    case 17: // pd2wu
        if (EditMapData[cx][cy + 1] < 1000)
            EditMapData[cx][cy + 1] = 2;
        cy--;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        case 6:
            writeMapData(interim, cx - 1, cy, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        case -1:
            fillMapData(cx - 1, cy - 1, cx + 1, cy + 1, EditMapData, -1);
            break;

        default:
            break;
        }

        break;

    case 18: // prd2wlu
        if (EditMapData[cx + 1][cy + 1] < 1000)
            EditMapData[cx + 1][cy + 1] = 2;

        cx--;
        cy--;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            break;

        default:
            EditMapData[cx + 1][cy + 1] = 0;
            break;
        }

        break;

    case 32: // keiru
        cx++;
        cy -= 2;
        if (count == 9)
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
        EditMapData[cx - 1][cy + 2] = 0;
        break;

    case 38: // keird
        cx++;
        cy += 2;
        if (count == 9)
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
        EditMapData[cx - 1][cy - 2] = 0;
        break;

    case 30: // keilu
        cx--;
        cy -= 2;
        if (count == 9)
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
        EditMapData[cx + 1][cy + 2] = 0;
        break;

    case 36: // keild
        cx--;
        cy += 2;
        if (count == 9)
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
        EditMapData[cx + 1][cy - 2] = 0;
        break;

    case 41: // du
        cy--;
        EditMapData[cx][cy + 1] = 0;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 3, cx + 1, cy - 1, returnNumber, EditMapData);
            break;
        case 6:
            writeMapData(interim, cx - 1, cy - 2, cx + 1, cy - 1, returnNumber, EditMapData);
            break;
        case 3:
            writeMapData(interim, cx - 1, cy - 1, cx + 1, cy - 1, returnNumber, EditMapData);
            fillMapData(0, cy - 2, 100, cy - 2, EditMapData, -1);
            break;

        default:
            break;
        }
        break;

    case 43: // dl
        cx--;
        EditMapData[cx + 1][cy] = 0;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 3, cy - 1, cx - 1, cy + 1, returnNumber, EditMapData);
            break;
        case 6:
            writeMapData(interim, cx - 2, cy - 1, cx - 1, cy + 1, returnNumber, EditMapData);
            break;
        case 3:
            writeMapData(interim, cx - 1, cy - 1, cx - 1, cy + 1, returnNumber, EditMapData);
            fillMapData(cx - 2, 0, cx - 2, 100, EditMapData, -1);
            break;

        default:
            break;
        }
        break;

    case 45: // dr
        cx++;
        EditMapData[cx - 1][cy] = 0;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx + 1, cy - 1, cx + 3, cy + 1, returnNumber, EditMapData);
            break;
        case 6:
            writeMapData(interim, cx + 1, cy - 1, cx + 2, cy + 1, returnNumber, EditMapData);
            break;
        case 3:
            writeMapData(interim, cx + 1, cy - 1, cx + 1, cy + 1, returnNumber, EditMapData);
            fillMapData(cx + 2, 0, cx + 2, 100, EditMapData, -1);
            break;

        default:
            break;
        }
        break;

    case 47: // dd
        cy++;
        EditMapData[cx][cy - 1] = 0;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy + 1, cx + 1, cy + 3, returnNumber, EditMapData);
            break;
        case 6:
            writeMapData(interim, cx - 1, cy + 1, cx + 1, cy + 2, returnNumber, EditMapData);
            break;
        case 3:
            writeMapData(interim, cx - 1, cy + 1, cx + 1, cy + 1, returnNumber, EditMapData);
            fillMapData(0, cy + 2, 100, cy + 2, EditMapData, -1);
            break;

        default:
            break;
        }
        break;

    case 100: // pu3su
        if (EditMapData[cx][cy - 1] != -1)
            EditMapData[cx][cy - 1] = 3; //自キャラの上が場外か奈落でなければアイテムを登録する
        cx++;
        if (count != 0 && count != -1)
        {
            writeMapData(interim, cx, cy - count, cx, cy - 1, returnNumber, EditMapData);
            if (count != 9)
                fillMapData(0, cy - count, 100, cy - count, EditMapData, 12);
        }
        EditMapData[cx - 1][cy] = 0;

        break;

    case 101: // pd3sd
        if (EditMapData[cx][cy + 1] != -1)
            EditMapData[cx][cy + 1] = 3;
        cx--;
        if (count != 0 && count != -1)
        {
            writeMapData(interim, cx, cy + 1, cx, cy + count, returnNumber, EditMapData);
            if (count != 9)
                fillMapData(0, cy + count, 100, cy + count, EditMapData, 12);
        }
        EditMapData[cx + 1][cy] = 0;

        break;

    case 102: // pl3sl
        if (EditMapData[cx - 1][cy] != -1)
            EditMapData[cx - 1][cy] = 3;
        cy--;
        if (count != 0 && count != -1)
        {
            writeMapData(interim, cx - count, cy, cx - 1, cy, returnNumber, EditMapData);
            if (count != 9)
                fillMapData(cx - count, 0, cx - count, 100, EditMapData, 12);
        }
        EditMapData[cx][cy + 1] = 0;
        break;

    case 103: // pr3sr
        if (EditMapData[cx + 1][cy] != -1)
            EditMapData[cx + 1][cy] = 3;
        cy++;
        if (count != 0 && count != -1)
        {
            writeMapData(interim, cx + 1, cy, cx + count, cy, returnNumber, EditMapData);
            if (count != 9)
                fillMapData(cx + count, 0, cx + count, 100, EditMapData, 12);
        }
        EditMapData[cx][cy - 1] = 0;

        break;

    case 110: // pu3lu
        if (EditMapData[cx][cy - 1] != -1)
            EditMapData[cx][cy - 1] = 3; //自キャラの上が場外か奈落でなければアイテムを登録する
        cx++;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy - 3, cx + 1, cy - 1, returnNumber, EditMapData);
            break;
        case 6:
            writeMapData(interim, cx - 1, cy - 2, cx + 1, cy - 1, returnNumber, EditMapData);
            break;
        default:
            break;
        }
        EditMapData[cx - 1][cy] = 0;
        break;

    case 111: // pd3ld
        if (EditMapData[cx][cy + 1] != -1)
            EditMapData[cx][cy + 1] = 3;
        cx--;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 1, cy + 1, cx + 1, cy + 3, returnNumber, EditMapData);
            break;
        case 6:
            writeMapData(interim, cx - 1, cy + 1, cx + 1, cy + 2, returnNumber, EditMapData);
            break;
        default:
            break;
        }
        EditMapData[cx + 1][cy] = 0;
        break;

    case 112: // pl3ll
        if (EditMapData[cx - 1][cy] != -1)
            EditMapData[cx - 1][cy] = 3;
        cy--;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 3, cy - 1, cx - 1, cy + 1, returnNumber, EditMapData);
            break;
        case 6:
            writeMapData(interim, cx - 2, cy - 1, cx - 1, cy + 1, returnNumber, EditMapData);
            break;
        default:
            break;
        }
        EditMapData[cx][cy + 1] = 0;
        break;

    case 113: // pr3lr
        if (EditMapData[cx + 1][cy] != -1)
            EditMapData[cx + 1][cy] = 3;
        cy++;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx + 1, cy - 1, cx + 3, cy + 1, returnNumber, EditMapData);
            break;
        case 6:
            writeMapData(interim, cx + 1, cy - 1, cx + 2, cy + 1, returnNumber, EditMapData);
            break;
        default:
            break;
        }
        EditMapData[cx][cy - 1] = 0;
        break;

    case 120: // pr0
        if (can_crush(EditMapData[cx + 1][cy]) == 1)
            EditMapData[cx + 1][cy] = 0;
        break;
    case 121: // pl0
        if (can_crush(EditMapData[cx - 1][cy]) == 1)
            EditMapData[cx - 1][cy] = 0;
        break;
    case 122: // pu0
        if (can_crush(EditMapData[cx][cy - 1]) == 1)
            EditMapData[cx][cy - 1] = 0;
        break;
    case 123: // pd0
        if (can_crush(EditMapData[cx][cy + 1]) == 1)
            EditMapData[cx][cy + 1] = 0;
        break;

    case 144: // dru
        cx++;
        cy--;
        EditMapData[cx - 1][cy + 1] = 0;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx + 1, cy - 3, cx + 3, cy - 1, returnNumber, EditMapData);
            break;

        case 4:
            writeMapData(interim, cx + 1, cy - 2, cx + 2, cy - 1, returnNumber, EditMapData);
            break;

        default:
            break;
        }
        break;

    case 145: // drd
        cx++;
        cy++;
        EditMapData[cx - 1][cy - 1] = 0;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx + 1, cy + 1, cx + 3, cy + 3, returnNumber, EditMapData);
            break;

        case 4:
            writeMapData(interim, cx + 1, cy + 1, cx + 2, cy + 2, returnNumber, EditMapData);
            break;

        default:
            break;
        }
        break;

    case 146: // dlu
        cx--;
        cy--;
        EditMapData[cx + 1][cy + 1] = 0;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 3, cy - 3, cx - 1, cy - 1, returnNumber, EditMapData);
            break;

        case 4:
            writeMapData(interim, cx - 2, cy - 2, cx - 1, cy - 1, returnNumber, EditMapData);
            break;

        default:
            break;
        }
        break;

    case 147: // dld
        cx--;
        cy++;
        EditMapData[cx + 1][cy - 1] = 0;
        switch (count)
        {
        case 9:
            writeMapData(interim, cx - 3, cy + 1, cx - 1, cy + 3, returnNumber, EditMapData);
            break;

        case 4:
            writeMapData(interim, cx - 2, cy + 1, cx - 1, cy + 2, returnNumber, EditMapData);
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }

    if_warp(&cx, &cy, EditMapData);

    if (interim == 0)
        jyougai(&i, &i, &i, &i, EditMapData, UseChInfo);

    EditMapData[cx][cy] = UseChInfo[2];

    UseChInfo[0] = cx;
    UseChInfo[1] = cy;

    return 0;
}

int drawMapData(int EditMapData[101][101], int UseChInfo[])
{
    int drawX, drawY;
    int b1x = 0, b1y = 0, b2x = 100, b2y = 100; //描写する範囲の４点を格納する変数
    int err = 0;

    int draw_range = setting.draw_length;
    b1x = UseChInfo[0] - draw_range;
    b1y = UseChInfo[1] - draw_range;
    b2x = UseChInfo[0] + draw_range;
    b2y = UseChInfo[1] + draw_range;

    if (setting.draw_outside == 0)
    {
        int jg1x, jg1y, jg2x, jg2y;                                  //場外変数
        jyougai(&jg1x, &jg1y, &jg2x, &jg2y, EditMapData, UseChInfo); //場外を算出
        if (b1x < jg1x)
            b1x = jg1x;
        if (b1y < jg1y)
            b1y = jg1y;
        if (b2x > jg2x)
            b2x = jg2x;
        if (b2y > jg2y)
            b2y = jg2y;
    }

    printf("\nマップ描写を行います...\n");

    for (drawY = b1y; drawY <= b2y; drawY++)
    {
        for (drawX = b1x; drawX <= b2x; drawX++)
        {
            if (EditMapData[drawX][drawY] == -2)
            {
                if (setting.unknown_Char[0] == 'n')
                {
                    printf("  ");
                }
                else
                    printf("%s", setting.unknown_Char);
            }
            else if (EditMapData[drawX][drawY] == 0)
            {
                if (setting.hole_Char[0] == 'n')
                {
                    printf("穴");
                }
                else
                    printf("%s", setting.hole_Char);
            }
            else if (EditMapData[drawX][drawY] == 1)
            {
                if (setting.target_Char[0] == 'n')
                {
                    printf("タ");
                }
                else
                    printf("%s", setting.target_Char);
            }
            else if (EditMapData[drawX][drawY] == -1)
            {
                if (setting.outside_Char[0] == 'n')
                {
                    printf("外");
                }
                else
                    printf("%s", setting.outside_Char);
            }
            else if (EditMapData[drawX][drawY] == 2)
            {
                if (setting.soil_Char[0] == 'n')
                {
                    printf("土");
                }
                else
                    printf("%s", setting.soil_Char);
            }
            else if (EditMapData[drawX][drawY] == 3)
            {
                if (setting.item_Char[0] == 'n')
                {
                    printf("ア");
                }
                else
                    printf("%s", setting.item_Char);
            }
            else if (EditMapData[drawX][drawY] == 4)
            {
                if (setting.geode_Char[0] == 'n')
                {
                    printf("ロ");
                }
                else
                    printf("%s", setting.geode_Char);
            }
            else if (EditMapData[drawX][drawY] == 5)
            {
                if (setting.fossil1_Char[0] == 'n')
                {
                    printf("化");
                }
                else
                    printf("%s", setting.fossil1_Char);
            }
            else if (EditMapData[drawX][drawY] == 6)
            {
                if (setting.fossil2_Char[0] == 'n')
                {
                    printf("化");
                }
                else
                    printf("%s", setting.fossil2_Char);
            }
            else if (EditMapData[drawX][drawY] == 7)
            {
                if (setting.fossil3_Char[0] == 'n')
                {
                    printf("化");
                }
                else
                    printf("%s", setting.fossil3_Char);
            }
            else if (EditMapData[drawX][drawY] == 8)
            {
                if (setting.fossil4_Char[0] == 'n')
                {
                    printf("化");
                }
                else
                    printf("%s", setting.fossil4_Char);
            }
            else if (EditMapData[drawX][drawY] == 20 || EditMapData[drawX][drawY] == 21 || EditMapData[drawX][drawY] == 22 || EditMapData[drawX][drawY] == 23)
            {
                if (setting.warp_Char[0] == 'n')
                {
                    printf("星");
                }
                else
                    printf("%s", setting.warp_Char);
            }
            else if (EditMapData[drawX][drawY] == 9)
            {
                if (setting.ammonite_Char[0] == 'n')
                {
                    printf("ｱﾝ");
                }
                else
                    printf("%s", setting.ammonite_Char);
            }
            else if (EditMapData[drawX][drawY] == 40 || EditMapData[drawX][drawY] == 41 || EditMapData[drawX][drawY] == 42 || EditMapData[drawX][drawY] == 43)
            {
                if (setting.bedrock6_Char[0] == 'n')
                {
                    printf("岩");
                }
                else
                    printf("%s", setting.bedrock6_Char);
            }
            else if (EditMapData[drawX][drawY] == 50 || EditMapData[drawX][drawY] == 51 || EditMapData[drawX][drawY] == 52 || EditMapData[drawX][drawY] == 53)
            {
                if (setting.bedrock15_Char[0] == 'n')
                {
                    printf("岩");
                }
                else
                    printf("%s", setting.bedrock15_Char);
            }
            else if (EditMapData[drawX][drawY] == 12)
            {
                if (setting.abyss_Char[0] == 'n')
                {
                    printf("奈");
                }
                else
                    printf("%s", setting.abyss_Char);
            }
            else if (EditMapData[drawX][drawY] == 60 || EditMapData[drawX][drawY] == 61 || EditMapData[drawX][drawY] == 62 || EditMapData[drawX][drawY] == 63)
            {
                if (setting.blackstar_Char[0] == 'n')
                {
                    printf("ｸﾎ");
                }
                else
                    printf("%s", setting.blackstar_Char);
            }

            else if (EditMapData[drawX][drawY] == 30 || EditMapData[drawX][drawY] == 31 || EditMapData[drawX][drawY] == 32 || EditMapData[drawX][drawY] == 33)
            {
                if (setting.teleport5_Char[0] == 'n')
                {
                    printf("TP");
                }
                else
                    printf("%s", setting.teleport5_Char);
            }

            else if (EditMapData[drawX][drawY] == 1000)
            {
                if (setting.C_Char[0] == 'n')
                {
                    printf("CC");
                }
                else
                    printf("%s", setting.C_Char);
            }
            else if (EditMapData[drawX][drawY] == 2000)
            {
                if (setting.H_Char[0] == 'n')
                {
                    printf("HH");
                }
                else
                    printf("%s", setting.H_Char);
            }
            else if (EditMapData[drawX][drawY] == 3000)
            {
                if (setting.a_Char[0] == 'n')
                {
                    printf("aa");
                }
                else
                    printf("%s", setting.a_Char);
            }
            else if (EditMapData[drawX][drawY] == 4000)
            {
                if (setting.s_Char[0] == 'n')
                {
                    printf("ss");
                }
                else
                    printf("%s", setting.s_Char);
            }
            else if (EditMapData[drawX][drawY] == 5000)
            {
                if (setting.e_Char[0] == 'n')
                {
                    printf("ee");
                }
                else
                    printf("%s", setting.e_Char);
            }
            else if (EditMapData[drawX][drawY] == 6000)
            {
                if (setting.r_Char[0] == 'n')
                {
                    printf("rr");
                }
                else
                    printf("%s", setting.r_Char);
            }
            else if (EditMapData[drawX][drawY] == 7000)
            {
                if (setting.O_Char[0] == 'n')
                {
                    printf("OO");
                }
                else
                    printf("%s", setting.O_Char);
            }
            else if (EditMapData[drawX][drawY] == 8000)
            {
                if (setting.n_Char[0] == 'n')
                {
                    printf("nn");
                }
                else
                    printf("%s", setting.n_Char);
            }
            else
                printf("他");
        }
        printf("\n");
    }
    if (err == 0)
    {
        printf("マップ描写が完了しました\n");
        return 0;
    }
    else
    {
        return err;
    }
}

int writeMapData(int interim, int x1, int y1, int x2, int y2, int returnNumber[], int EditMapData[101][101]) //引数の座標にreturuNumberを書き込む
{
    int sx = 0, sy = 0; //処理X、処理Yという意味
    int num = 0;
    int i = 0;

    if (interim == 0)
    {
        for (sy = y1; sy <= y2; sy++)
        {
            for (sx = x1; sx <= x2; sx++)
            {
                EditMapData[sx][sy] = returnNumber[num];
                // printf("%d,", returnNumber[num]);
                num++;
            }
        }
    }
    else if (interim == 1) //最適なコマンド選出の際などの仮のデータを扱う場合
    {
        for (sy = y1; sy <= y2; sy++)
        {
            for (sx = x1; sx <= x2; sx++)
            {
                if (EditMapData[sx][sy] == -2) //もし処理座標が未知キャラだったら
                {
                    EditMapData[sx][sy] = -9999; //"既知なはずの座標"として登録する
                    returnNumber[num] = 10000;   // interimが1の場合はreturnNumberは情報を持っていないため、新規に確認した座標を表すのに使う
                    i++;
                }
                else
                    returnNumber[num] = EditMapData[sx][sy];
                num++;
            }
        }
    }

    return 0;
}

int jyougai(int *x1, int *y1, int *x2, int *y2, int MapData[101][101], int UseChInfo[])
{
    int sx, sy;
    int cx, cy;
    *x1 = 0;
    *y1 = 0;
    *x2 = 100;
    *y2 = 100;

    cx = UseChInfo[0];
    cy = UseChInfo[1];

    for (sx = 0; sx <= cx - 1; sx++) //左端の場外を求める
    {
        for (sy = 0; sy <= 100; sy++)
        {
            if (MapData[sx][sy] == 12) //奈落だったら
            {
                if (MapData[sx][sy + 1] == 12 && MapData[sx][sy + 2] == 12) //さらに奈落が２連続で存在したら
                {
                    *x1 = sx - 1;
                    fillMapData(0, 0, *x1, 100, MapData, -1);
                    break;
                }
            }
        }
    }
    for (sx = cx + 1; sx <= 100; sx++) //右端の場外を求める
    {
        for (sy = 0; sy <= 100; sy++)
        {
            if (MapData[sx][sy] == 12) //奈落だったら
            {
                if (MapData[sx][sy + 1] == 12 && MapData[sx][sy + 2] == 12) //さらに奈落が２連続で存在したら
                {
                    *x2 = sx + 1;
                    fillMapData(*x2, 0, 100, 100, MapData, -1);
                    break;
                }
            }
        }
    }
    for (sy = 0; sy <= cy - 1; sy++) //上端の場外を求める
    {
        for (sx = 0; sx <= 100; sx++)
        {
            if (MapData[sx][sy] == 12) //奈落だったら
            {
                if (MapData[sx + 1][sy] == 12 && MapData[sx + 2][sy] == 12) //さらに奈落が２連続で存在したら
                {
                    *y1 = sy - 1;
                    fillMapData(0, 0, 100, *y1, MapData, -1);
                    break;
                }
            }
        }
    }
    for (sy = cy + 1; sy <= 100; sy++) //下端の場外を求める
    {
        for (sx = 0; sx <= 100; sx++)
        {
            if (MapData[sx][sy] == 12) //奈落だったら
            {
                if (MapData[sx + 1][sy] == 12 && MapData[sx + 2][sy] == 12) //さらに奈落が２連続で存在したら
                {
                    *y2 = sy + 1;
                    fillMapData(0, *y2, 100, 100, MapData, -1);
                    break;
                }
            }
        }
    }

    return 0;
}

void fillMapData(int x1, int y1, int x2, int y2, int EditMapData[101][101], int ch_num)
{
    int sx, sy;
    for (sx = x1; sx <= x2; sx++)
    {
        for (sy = y1; sy <= y2; sy++)
        {
            EditMapData[sx][sy] = ch_num;
        }
    }
}

int if_warp(int *cx, int *cy, int EditMapData[101][101])
{
    int warp = 0;
    //ワープ系マスを踏んだ際の処理を記述する
    if (EditMapData[*cx][*cy] == 60 || EditMapData[*cx][*cy] == 61 || EditMapData[*cx][*cy] == 62 || EditMapData[*cx][*cy] == 63)
    {
        warp = 1;
        *cx = 25;
        *cy = 25;
        fillMapData(0, 0, 100, 100, EditMapData, -2); // MapDataを未知でリセット
    }
    else if (EditMapData[*cx][*cy] == 20)
    {
        warp = 1;
        *cx += 10;
    }
    else if (EditMapData[*cx][*cy] == 21)
    {
        warp = 1;
        *cx -= 10;
    }
    else if (EditMapData[*cx][*cy] == 22)
    {
        warp = 1;
        *cy -= 10;
    }
    else if (EditMapData[*cx][*cy] == 23)
    {
        warp = 1;
        *cy += 10;
    }
    else if (EditMapData[*cx][*cy] == 30)
    {
        warp = 1;
        *cx += 5;
    }
    else if (EditMapData[*cx][*cy] == 31)
    {
        warp = 1;
        *cx -= 5;
    }
    else if (EditMapData[*cx][*cy] == 32)
    {
        warp = 1;
        *cy -= 5;
    }
    else if (EditMapData[*cx][*cy] == 33)
    {
        warp = 1;
        *cy += 5;
    }

    if (*cx >= 100 || *cx <= 0 || *cy >= 100 || *cy <= 0)
    {
        *cx = 50;
        *cy = 50;
        fillMapData(0, 0, 100, 100, EditMapData, -2); // MapDataを未知でリセット
    }

    return warp;
}

int can_crush(int ch_num)
{
    switch (ch_num)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return 1;

    default:
        return 0;
    }
}
