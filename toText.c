//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 2
//Due 2/28/16

#include "headers.h"

void toText(FILE *inFile, FILE *outFile){
	
	//variables
	char inputString[MAX_STR_LEN];
	int string_len;
	int number;
	char * copied_str;
	
	//string interpretation for file output
	while((string_len = fgetc(inFile)) != EOF){
		//allocate malloc accordingly
		copied_str = malloc(string_len);
		
		//read string from file
		fread(&inputString, sizeof(char), string_len, inFile);
		
		//append null terminator
		inputString[string_len] = '\0';
		
		//copy string into mallo'ed string
		strcpy(copied_str, inputString);
		
		//compute number from file
		fread(&number, sizeof(int), 1, inFile);
		
		//print data to file
		fprintf(outFile, "%s\t%d", copied_str, number);
		
		//place newlines in output file as needed
		if(fgetc(inFile) != EOF){
			//seek back 1 spot
			fseek(inFile, -1, SEEK_CUR);
			//print the \n if not EOF
			fprintf(outFile, "\n");
			
		}
	}
	//free malloc'ed string
	free(copied_str);
}