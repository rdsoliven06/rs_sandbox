#include <stdio.h>
#include <time.h>
#include "atm.h"

/*Note: This will print current system's time*/
void current_time(void){
	time_t now;
	time(&now);
	printf("\t\t\t\t%s", ctime(&now));
}
