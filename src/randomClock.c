#include "randomClock.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int32_t incrementMins(struct tm *curTime){
	int32_t randMins = curTime->tm_min + (rand() % MINUTES_CAP);

	return randMins;
}

void displayTime(){
	time_t timeSeconds = time(0);
	struct tm *displayTime = localtime(&timeSeconds);

	int32_t randMins = incrementMins(displayTime);
	uint8_t hourOffset = 0;
	if(randMins > 59){
		randMins = randMins % 60;
		hourOffset = 1;
	}

	int32_t timeHour = displayTime->tm_hour;
	int32_t displayHour = ((timeHour + hourOffset + 11) % 12) + 1;
	char *meridiem = ((timeHour + hourOffset) % 24) >= 12 ? "PM" : "AM";

	printf("%" PRId32 ":%02" PRId32 " %s\n", displayHour, randMins, meridiem);
}
