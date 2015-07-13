#ifdef TOOLS
#define TOOLS
#include "data_set.h"

// プログラム本体の初期化
void init_program(DAY, int);
// ゲームの初期化
void init_game(PLAYER);
// ダイスを振る
int throw_dice(int);
// プレイヤーを動かす
void move_player(PLAYER);
// イベント発生時にどうにかする
void switch_event(PLAYER, int);

#endif
