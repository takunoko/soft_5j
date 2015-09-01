#include <stdio.h>

#include "data_set.h"
#include "tools.h"

#include "event.h"


void test_function(){
    DAY_EVENT day_list[50];  // 適当に50日分確保しておく
    PLAYER player_list[10];  // 多くても10人でしょ。。。
    int day_size, player_size;
    int mgame_player_list[10];

    init_program(20);

    // day_size = load_day_event_data(day_list, DAY_EVENT_FILE_NAME);
    // player_size = init_game(player_list);

	int num = throw_dice(10);
	printf("%d\n",num);


    // e_sea(player_list, int_list);
}

int main(void){
    test_function();

   	return 0;
}

