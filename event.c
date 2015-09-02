#include <unistd.h>  // sleep
#include <stdio.h>

#include "data_set.h"
#include "tools.h"

/* memo :
 * player_list[] は全員分のプレイヤーの情報(構造体)
 * p_num[] はリスト形式でゲームをプレイする人の番号がリスト形式になっている
 */

void e_sea(PLAYER player_list[], int p_num[]){
    printf("海イベント\n");
    printf("サイコロを振ってでた目の数*10の充実ポイントをゲット\n\n");

    int dice;
    int add_J_pt;

    int i;
    for (i=0; p_num[i] != -1; i++){
        printf("%sのターン\n", player_list[p_num[i]].name);
//        sleep(1);
        dice = throw_dice(10)+1;
        add_J_pt = dice*10;
        printf("%dの目が出た。\n%sに充実ポイント+%d!!\n", dice, player_list[p_num[i]].name, add_J_pt);
//        sleep(1);
        player_list[p_num[i]].K_pt += 0;
        player_list[p_num[i]].J_pt += add_J_pt;
        // 常にどこかに全員のステータスを表示しておく関数
        disp_plyaer_status(&player_list[p_num[i]]);
    }
}

void e_bbq(PLAYER player_list[], int p_num[]){

}

void e_mountain(PLAYER player_list[], int p_num[]){

}

void e_karaoke(PLAYER player_list[], int p_num[]){

}

void e_swimming(PLAYER player_list[], int p_num[]){

}

void e_study(PLAYER player_list[], int p_num[]){

}

void e_bowling(PLAYER player_list[], int p_num[]){

}

void e_game(PLAYER player_list[], int p_num[]){

}


void e_drive(PLAYER player_list[], int p_num[]){

}

void e_shopping(PLAYER player_list[], int p_num[]){

}
