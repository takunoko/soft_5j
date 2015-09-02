#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // sleep
#include <time.h>  // srand初期化

#include "data_set.h"
#include "event.h"

// はい:いいえ 戻り値 はい=1 いいえ=0
int yes_no(void){
    char input;
    printf("はい:y | いいえ:n >> ");
    scanf("%c%*c", &input);
    if(input == 'Y' || input == 'y')
        return 1;
    else
        return 0;
}

void disp_plyaer_status(PLAYER *player){
    printf("-----%s-----\n", player->name);
    printf("課題ポイント : %5d\n", player->K_pt);
    printf("充実ポイント : %5d\n", player->J_pt);
}

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
void move_player(DAY_EVENT day_list[], PLAYER *player){
    int dice;
    printf("dice...\n");
    sleep(1);
    // 最終的には乱数でも、ダイスを振るような動作
    dice = throw_dice(6), dice+=1;  // 1~6が出るように調整
    printf("夏休みが %d 日進んだ。\n", dice);
    sleep(1);
    player->position += dice;
    printf("%d日目。\n%s\n", player->position, day_list[player->position].content);
    player->K_pt += day_list[player->position].K_pt;  // プレイヤーのステータスを増減
    player->J_pt += day_list[player->position].J_pt;  // プレイヤーのステータスを増減
    printf("課題ポイント : %5d -> %5d\n",day_list[player->position].K_pt, player->K_pt);
    printf("充実ポイント : %5d -> %5d\n\n",day_list[player->position].J_pt, player->J_pt);
}

// イベントに参加するプレイーヤーを決定
void select_event_player(PLAYER player_list[], int p_size, int *p_list){
    char input;

    int p_cnt=0;
    int i;
    for(i=0; i<p_size; i++){
        printf("%sはイベントに参加しますか？\n", player_list[i].name);
        if(yes_no() == 1){
            p_list[p_cnt] = i;
            p_cnt++;
        }
    }
    p_list[p_cnt] = -1;  // 最後の参加プレイヤーの後ろに-1を代入しておく
}

// イベント発生時にどうにかする
void start_event(PLAYER *player_list, int *p_list){
    if(p_list[0] == -1){
        printf("参加者がいなかったため、今回のイベントはスキップされました。\n");
        return;
    }

    printf("\n夏の楽しいイベントの始まりです。\n");
    int event;
    event = throw_dice(6); // 乱数によりイベントを決定
    event = 0;  // デバッグ用に1のみを出す
    switch(event){
        case 0:
            e_sea(player_list, p_list);
            break;
        case 1:
            e_bbq(player_list, p_list);
            break;
        case 2:
            e_mountain(player_list, p_list);
            break;
        default:
            printf("何かおかしい...");
            break;
    }

}
