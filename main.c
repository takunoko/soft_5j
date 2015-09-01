#include <stdio.h>
#include <unistd.h>  // sleep

#include "data_set.h"
#include "tools.h"

#include "event.h"

void game_main(DAY_EVENT*, int, PLAYER*, int);

void test_function(){
    DAY_EVENT day_list[50];  // 適当に50日分確保しておく
    PLAYER player_list[10];  // 多くても10人でしょ。。。
    int day_size, player_size;

    init_program(20);

    day_size = load_day_event_data(day_list, DAY_EVENT_FILE_NAME);
    player_size = init_game(player_list);

	int num = throw_dice(10);
	printf("%d\n",num);

    game_main(day_list, day_size, player_list, player_size);

    // e_sea(player_list, int_list);
}

void game_main(DAY_EVENT day_list[], int day_size, PLAYER player_list[], int player_size){
    int mgame_player_list[10];  // ミニゲーム参加管理用

    while(1){
        int p_cnt;
        int dice;
        // すべてのプレイヤーが一度行動
        for(p_cnt = 0; p_cnt < player_size; p_cnt++){
            // マップorカレンダー的なものを表示して、プレイヤーの位置を表示したい。
            printf("-----%sのターン-----\n", player_list[p_cnt].name);
            sleep(1);
            dice = throw_dice(6), dice+=1;  // 1~6が出るように調整
            printf("夏休みが %d 日進んだ。\n", dice);
            player_list[p_cnt].position += dice;
            sleep(1);
            printf("%d日目。 %s\n", player_list[p_cnt].position, day_list[player_list[p_cnt].position].content);
            player_list[p_cnt].K_pt += day_list[player_list[p_cnt].position].K_pt;  // プレイヤーのステータスを増減
            player_list[p_cnt].J_pt += day_list[player_list[p_cnt].position].J_pt;  // プレイヤーのステータスを増減
            printf("課題ポイント : %5d -> %5d\n",day_list[player_list[p_cnt].position].K_pt, player_list[p_cnt].K_pt);
            printf("充実ポイント : %5d -> %5d\n",day_list[player_list[p_cnt].position].J_pt, player_list[p_cnt].J_pt);
        }
        break;
    }
}

int main(void){
    test_function();

   	return 0;
}

