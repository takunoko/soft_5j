// #ifdef TOOLS
// #define TOOLS

// プログラム本体の初期化
int init_program(int);
// ゲームの初期化
int init_game(PLAYER*);
// ダイスを振る
int throw_dice(int);
// プレイヤーを動かす
void move_player(PLAYER*);
// イベント発生時にどうにかする
void switch_event(PLAYER*, int);
// イベントファイルを読み込む
int load_day_event_data(DAY_EVENT*, char*);

// #endif
