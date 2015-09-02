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
        int move;
        // すべてのプレイヤーが一度行動
        for(p_cnt = 0; p_cnt < player_size; p_cnt++){
            // マップorカレンダー的なものを表示して、プレイヤーの位置を表示したい。
            printf("-----%sのターン-----\n", player_list[p_cnt].name);
            move_player(day_list, &player_list[p_cnt]);
        }
        select_event_player(player_list, player_size, mgame_player_list);
        start_event(player_list, mgame_player_list);

        break;
    }
}

int main(void){
    test_function();

   	return 0;
}

