#include "setting.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern SETTING setting;

int read_settingfile(char *filePath);
void setting_reset();

int read_settingfile(char *filePath)
{
    FILE *f = fopen(filePath, "r");
    if(!f)
    {
        //fclose(f);
        printf("設定ファイルの読み込みに失敗しました、%sの生成を行います。\n", filePath);
        f = fopen(filePath, "w");
        fprintf(f, "このファイルに[設定項目名][値]を入力して保存してください,char\n");
        printf("設定ファイルの生成が終了しました");
        fclose(f);
        return 1;
    }
    else
    {
        int gyou;
        char koumoku[256], naiyou[256];

        for (gyou = 0; gyou <= 255;gyou++)
        {
            //setting[gyou][0]= 'n';
        }
        setting_reset();

        for (gyou = 0; gyou <= 100; gyou++) //設定項目の上限に合わせて数字を変える
        {
            fscanf(f, "%[^,],%s\n", koumoku, naiyou);
            if (strcmp(koumoku, "tesuto") == 0)
            {
                strcpy(setting.test, naiyou);
            }
            if (strcmp(koumoku, "描写距離") == 0)
            {
                //strcpy(setting.draw_length, naiyou);
                setting.draw_length = atoi(naiyou);
            }
            if (strcmp(koumoku, "場外の描写") == 0)
            {
                //strcpy(setting.draw_outside, naiyou);
                setting.draw_outside = atoi(naiyou);
            }

            if(strcmp(koumoku, "未知キャラクタ") == 0)
            {
                strcpy(setting.unknown_Char, naiyou);
            }
            if(strcmp(koumoku, "穴キャラクタ") == 0)
            {
                strcpy(setting.hole_Char, naiyou);
            }
            if(strcmp(koumoku, "ターゲットキャラクタ") == 0)
            {
                strcpy(setting.target_Char, naiyou);
            }
            if(strcmp(koumoku, "場外キャラクタ") == 0)
            {
                strcpy(setting.outside_Char, naiyou);
            }
            if(strcmp(koumoku, "土キャラクタ") == 0)
            {
                strcpy(setting.soil_Char, naiyou);
            }
            if(strcmp(koumoku, "アイテムキャラクタ") == 0)
            {
                strcpy(setting.item_Char, naiyou);
            }
            if(strcmp(koumoku, "ジオードキャラクタ") == 0)
            {
                strcpy(setting.geode_Char, naiyou);
            }
            if(strcmp(koumoku, "化石1キャラクタ") == 0)
            {
                strcpy(setting.fossil1_Char, naiyou);
            }
            if(strcmp(koumoku, "化石2キャラクタ") == 0)
            {
                strcpy(setting.fossil2_Char, naiyou);
            }
            if(strcmp(koumoku, "化石3キャラクタ") == 0)
            {
                strcpy(setting.fossil3_Char, naiyou);
            }
            if(strcmp(koumoku, "化石4キャラクタ") == 0)
            {
                strcpy(setting.fossil4_Char, naiyou);
            }
            if(strcmp(koumoku, "ワープキャラクタ") == 0)
            {
                strcpy(setting.warp_Char, naiyou);
            }
            if(strcmp(koumoku, "アンモナイトキャラクタ") == 0)
            {
                strcpy(setting.ammonite_Char, naiyou);
            }
            if(strcmp(koumoku, "岩盤6キャラクタ") == 0)
            {
                strcpy(setting.bedrock6_Char, naiyou);
            }
            if(strcmp(koumoku, "岩盤15キャラクタ") == 0)
            {
                strcpy(setting.bedrock15_Char, naiyou);
            }
            if(strcmp(koumoku, "奈落キャラクタ") == 0)
            {
                strcpy(setting.abyss_Char, naiyou);
            }
            if(strcmp(koumoku, "ブラックスターキャラクタ") == 0)
            {
                strcpy(setting.blackstar_Char, naiyou);
            }
            if(strcmp(koumoku, "5マスTPキャラクタ") == 0)
            {
                strcpy(setting.teleport5_Char, naiyou);
            }
            

            if(strcmp(koumoku, "クライアントCキャラクタ") == 0)
            {
                strcpy(setting.C_Char, naiyou);
            }
            if(strcmp(koumoku, "クライアントHキャラクタ") == 0)
            {
                strcpy(setting.H_Char, naiyou);
            }
            if(strcmp(koumoku, "クライアントaキャラクタ") == 0)
            {
                strcpy(setting.a_Char, naiyou);
            }
            if(strcmp(koumoku, "クライアントsキャラクタ") == 0)
            {
                strcpy(setting.s_Char, naiyou);
            }
            if(strcmp(koumoku, "クライアントeキャラクタ") == 0)
            {
                strcpy(setting.e_Char, naiyou);
            }
            if(strcmp(koumoku, "クライアントrキャラクタ") == 0)
            {
                strcpy(setting.r_Char, naiyou);
            }
            if(strcmp(koumoku, "クライアントOキャラクタ") == 0)
            {
                strcpy(setting.O_Char, naiyou);
            }
            if(strcmp(koumoku, "クライアントnキャラクタ") == 0)
            {
                strcpy(setting.n_Char, naiyou);
            }
            
            
        }

        printf("設定ファイルの内容を反映しました");
        fclose(f);
    }


    return 0;
}

void setting_reset()
{
    setting.draw_length = 20;
    setting.draw_outside = 0;
    setting.test[0] = 'n';
    setting.unknown_Char[0] = 'n';
    setting.hole_Char[0] = 'n';
    setting.target_Char[0] = 'n';
    setting.outside_Char[0] = 'n';
    setting.soil_Char[0] = 'n';
    setting.item_Char[0] = 'n';
    setting.geode_Char[0] = 'n';
    setting.fossil1_Char[0] = 'n';
    setting.fossil2_Char[0] = 'n';
    setting.fossil3_Char[0] = 'n';
    setting.fossil4_Char[0] = 'n';
    setting.warp_Char[0] = 'n';
    setting.ammonite_Char[0] = 'n';
    setting.bedrock6_Char[0] = 'n';
    setting.bedrock15_Char[0] = 'n';
    setting.abyss_Char[0] = 'n';
    setting.blackstar_Char[0] = 'n';
    setting.teleport5_Char[0] = 'n';
    setting.C_Char[0] = 'n';
    setting.H_Char[0] = 'n';
    setting.a_Char[0] = 'n';
    setting.s_Char[0] = 'n';
    setting.e_Char[0] = 'n';
    setting.r_Char[0] = 'n';
    setting.O_Char[0] = 'n';
    setting.n_Char[0] = 'n';
}