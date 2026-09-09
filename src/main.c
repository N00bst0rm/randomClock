#include "randomClock.h"
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>

// Purpose: a motivator to get out of bed earlier as one won't precisely know what the time is,
// therefore possibly making one think that they will be late for work if they don't get up now
//
// Configure MINUTES_CAP in randomClock.h for a different range

int main(){
	srand(time(NULL));

	while(1){
		char *output = getTime();
		printf("%s\n", output);
		free(output);

		time_t timeSeconds = time(0);
		struct tm *displayTime = localtime(&timeSeconds);

		// Sleep until the next minute, avoiding busy waiting and conditionals
		sleep(60 - displayTime->tm_sec);
	}
	return 0;
}
