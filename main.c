#include <stdio.h>

#include "tools.h"
#include "event.h"

int main(void){
	int num = throw_dice(3);
	printf("%d\n",num);
	return 0;
}
