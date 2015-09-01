#include "data_set.h"

/* memo :
 * player_list[] は全員分のプレイヤーの情報(構造体)
 * p_num[] はリスト形式でゲームをプレイする人の番号がリスト形式になっている
 */

void e_sea(PLAYER player_list[], int p_num[]){
    int i;
    for (i=0; p_num[i] != -1; i++){
        player_list[i].K_pt -= 3;
        player_list[i].J_pt += 3;
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
