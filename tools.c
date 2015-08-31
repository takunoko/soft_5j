#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "data_set.h"

// プログラム本体の初期化
void init_program(DAY, int){
    // 乱数初期化
    srand((unsigned)time(NULL));

}

// ダイスを振る
int throw_dice(int max_num){
    num = rand()%max_num;
	return num;
}

// ゲームの初期化
void init_game(PLAYER){
}

// ダイスを振る
int throw_dice(int){
}

// プレイヤーを動かす
void move_player(PLAYER){
}

// イベント発生時にどうにかする
void switch_event(PLAYER, int){
}
