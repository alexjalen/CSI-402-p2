//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 2
//Due 2/28/16

#include "headers.h"

void die(char * message){
	fprintf(stderr, "%s\n", message);
	fflush(stderr);
	exit(1);
}

void debug(char * message){
	printf("%s\n", message);
	fflush(stdout);
}