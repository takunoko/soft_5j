// #ifdef DATA_SET
// #define DATA_SET

// プレイヤー構造体
typedef struct{
	char name[20];
    int position;
	int K_pt;
	int J_pt;
	int flg;
}PLAYER;

// 日付イベント構造体
typedef struct{
	char content[200];
	int K_pt;
	int J_pt;
}DAY_EVENT;

#define DEFAULT_K_PT 1000
#define DEFAULT_J_PT 10

#define DAY_EVENT_FILE_NAME "day_event.csv"

// #endif
