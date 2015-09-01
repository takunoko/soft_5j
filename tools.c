#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "data_set.h"

// プログラム本体の初期化
void init_program(int tmp){
    // 乱数初期化
    srand((unsigned)time(NULL));
}

// 日付イベントの読み込み
int load_day_event_data(DAY_EVENT day_event[], char *file_name){
    FILE *fp;
    fp = fopen(file_name, "r");
    if(fp == NULL){
        printf("Can not open %s file\n", file_name);
    }

    int K_pt, J_pt;
    char K_sign, J_sign;
    char e[200];
    int ret;

    char readline[300] = {'\0'};

    int day_count = 0;
    while(fgets(readline, 300, fp) != NULL){
        if(readline[0] == '#' || readline[0] == '\n'){
            // printf("skip\n");
        }else{
            // ,の前後にスペースがあるとうまくいかない仕様
            // なんとか改良したい
            sscanf(readline, "%[^,],%c,%d,%c,%d%*c", e, &K_sign, &K_pt, &J_sign, &J_pt);
            printf( "event_name: %s\n\
                    K_pt : %c %d\n\
                    J_pt : %c %d\n", e, K_sign, K_pt, J_sign, J_pt);

            K_pt = (K_sign == '-') ? K_pt*-1 : K_pt;
            J_pt = (J_sign == '-') ? J_pt*-1 : J_pt;
            strncpy(day_event[day_count].content, e, 200);
            day_event[day_count].K_pt = K_pt;
            day_event[day_count].J_pt = J_pt;
            day_count++;
        }
    }

    fclose(fp);

    return day_count;
}

// ダイスを振る
int throw_dice(int max_num){
    // エフェクト?とかを作成してゲームっぽく。
    int num = rand()%max_num;
	return num;
}

// ゲームの初期化
// p_size : プレイヤーの数
int init_game(PLAYER *player_list){

#define DEGUB_INIT_GAME
#ifdef DEGUB_INIT_GAME
    int p_size = 3;
    int i;
    char name_list[][20] = {"aaa","iii","uuu"};
    for(i=0; i<3; i++){
        strncpy(player_list[i].name, name_list[i], 20);
        player_list[i].J_pt = DEFAULT_J_PT;
        player_list[i].K_pt = DEFAULT_K_PT;
        player_list[i].position = 0;
    }
#else
    int p_size;
    char tmp_name[20];
    char input_tmp;

    printf("Player size : "),   scanf("%d", &p_size);

    int i;
    for(i=0; i<p_size; i++){
        do{
            printf("Player %d name >> ",i), scanf("%s%*c", tmp_name);
            printf("Your Name : %s\n Yes:y | No:n >> ", tmp_name), scanf("%c%*c", &input_tmp);
        }while(!(input_tmp == 'y' || input_tmp == 'Y'));

        strncpy(player_list[i].name, tmp_name, 20);
        player_list[i].J_pt = DEFAULT_J_PT;
        player_list[i].K_pt = DEFAULT_K_PT;
        player_list[i].position = 0;
    }
#endif

    return p_size;
}

// プレイヤーを動かす
void move_player(PLAYER player){

}

// イベント発生時にどうにかする
void switch_event(PLAYER *player_list, int *p_list){

}
