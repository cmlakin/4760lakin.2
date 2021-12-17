#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "config.h"

// pointer to return error value
const char * perror_arg0 = "testsim";

int main(int argc, char* argv[]){

	if (argc != 4) {
		printf("usage: testsim repeat wait\n");
		int j;
    printf("argc = %d\n",argc);
    for(j=0;j<argc;j++)
    {
        printf("argv[%i]: %s\n", j, argv[j]);
    }
		return -1;
	}

	int i;
	int id;
	char perror_buf[50];
	char logbuf[200];
	char buf2[20];

	int repeats = atoi(argv[1]); // num times to repeat loop
	int seconds = atoi(argv[2]); // num seconds to wait/sleep

	id = atoi(argv[3]); // process id used for bakery algorithm

	// create the string from the program name
	snprintf(perror_buf, sizeof(perror_buf), "%s: Error: ", "testsim");

	printf("testsim[%d]: Started with %d %d\n", id, repeats, seconds);

	snprintf(logbuf, sizeof(logbuf),
					 "Time\t\tPID\tCurrent Iteration\tTotal Iterations");
	logmsg(logbuf);

	for (i = 0; i < repeats; i++) {

		snprintf(buf2, sizeof(buf2), "%i %i", i, repeats);


		snprintf(buf2, sizeof(buf2), "%i\t%i\t%i", id, i, repeats);
		put_timestamp(logbuf, sizeof(logbuf), buf2);

    logmsg(logbuf);
		sleep(seconds);

	}

	return 0;
}
