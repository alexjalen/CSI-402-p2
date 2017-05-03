//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 2
//Due 2/28/16

#include "headers.h"
#include "prototypes.h"

int main (int argc, char *argv[]){
	
	//variables
	FILE *inFile;
	FILE *outFile;
	
	
	//tests for correct number of arguments
	if(argc < 3 || argc > 4){
		die("Incorrect number of arguments.");
	}
	
	//check input file for validity
	if((inFile = fopen(argv[2], "r")) == NULL){
		//then quit
		die("Could not open input file.");
	}
	
	//if has 4 arguments then try and open output file
	if(argc == 4){
	//check input file for validity
		if((outFile = fopen(argv[3], "w")) == NULL){
			//then quit
			die("Could not open output file.");
		}
	}
	
	//test flags for correct input	
	if(argc == 4){
		if((strcmp("-t", argv[1]) != 0) && (strcmp("-b", argv[1]) != 0)){
			die("Incorrect flag.");
		}
	}else{
		//must be 3 arguments
		if(strcmp("-s", argv[1]) != 0){
			die("Incorrect flag.");
		}
	}
	
	//select correct flag to interpret
	if(strcmp("-t", argv[1]) == 0){
		//convert from text to binary
		toBinary(inFile, outFile);
	}
	else if(strcmp("-b", argv[1]) == 0){
		//convert from binary file to txt file		
		toText(inFile, outFile);
		
	}else{
		//do stats on the binary file
		binStats(inFile, argv[2]);
	}
	
	//remember to close files that were opened
	fclose(inFile);
	fclose(outFile);
	
	return 0;
	
}//end main