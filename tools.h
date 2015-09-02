// #ifdef TOOLS
// #define TOOLS

// プログラム本体の初期化
int init_program(int);
// ゲームの初期化
int init_game(PLAYER*);
// ダイスを振る
int throw_dice(int);
// プレイヤーを動かす
void move_player(DAY_EVENT*, PLAYER*);
// イベント発生時にどうにかする
void start_event(PLAYER*, int*);
// イベントファイルを読み込む
int load_day_event_data(DAY_EVENT*, char*);
// イベント参加者リストの作成
void select_event_player(PLAYER*, int, int*);
// はい:いいえの質問
int yes_no(void);
// 一人分のステータス表示
void disp_plyaer_status(PLAYER *player);
// #endif
