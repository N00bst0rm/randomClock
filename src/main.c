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
		time_t timeSeconds = time(0);
		struct tm *displayTime = localtime(&timeSeconds);

		char *output = getTime();
		printf("Current time (24hr): %02d:%02d -> Randomized time (12hr): %s\n", displayTime->tm_hour, displayTime->tm_min, output);
		free(output);

		// Sleep until the next minute, avoiding busy waiting and conditionals
		sleep(60 - displayTime->tm_sec);
	}
	return 0;
}
