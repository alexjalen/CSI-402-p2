//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 2
//Due 2/28/16

#include "headers.h"

void binStats(FILE *inFile, char * fileName){
	//find length of shortest and longest string
	//find min and max integer
	
	//variables
	int string_len;
	int number;
	int short_str;
	int long_str;
	int min_int;
	int max_int;
	
	//assume first word is longest and shortest string
	short_str = long_str = fgetc(inFile);
	
	//fseek over string, because unneeded data
	fseek(inFile, short_str, SEEK_CUR);
	
	//assume min and max int is the current number
	fread(&min_int, sizeof(int), 1, inFile);
	max_int = min_int;
	
	
	while((string_len = fgetc(inFile)) != EOF){
		//finds shortest string
		if(string_len < short_str){
			short_str = string_len;
		}
		
		//finds longest string
		if(string_len > long_str){
			long_str = string_len;
		}
		
		//fseek over string, because unneeded data
		fseek(inFile, string_len, SEEK_CUR);
		
		//read in next integer
		fread(&number, sizeof(int), 1, inFile);
		
		//find lowest int
		if(number < min_int){
			min_int = number;
		}
		
		//find highest int
		if(number > max_int){
			max_int = number;
		}

	}//end while
	
	//print to stdout
	printf("\nFor %s:\n", fileName);
	printf("Length of shortest string = %d\n", short_str);
	printf("Length of longest string = %d\n", long_str);
	printf("Value of maximum integer = %d\n", max_int);
	printf("Value of minimum integer = %d\n", min_int);
	
	fflush(stdout);
}