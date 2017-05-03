//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 2
//Due 2/28/16

#include "headers.h"

//void toBinary(char * inputString, int number,FILE *outFile){
void toBinary(FILE *inFile, FILE *outFile){

	
	char inputString[MAX_STR_LEN];
	int number;
	unsigned char unsigned_length;
	unsigned int unsigned_number;
	

	
	while(fscanf(inFile, "%s\t%d", inputString, &number) != EOF){

		//length of word
		unsigned_length = strlen(inputString);
		
		//number in file
		unsigned_number = (unsigned int)number;
		
		//print to file using fwrite
		//string length
		fwrite(&unsigned_length, sizeof(char), 1, outFile);
		
		//string itself
		fprintf(outFile, "%s", inputString);
		
		//number in file
		fwrite(&unsigned_number, sizeof(int), 1, outFile);
	}
	
}