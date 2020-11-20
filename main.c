/*
CSCI Lab 6
Written by Jared Weiss
*/

#include "fns.h"

int main(void) {
	// Execute ps aux and redirect the output to ps.txt
	run_command("/bin/ps", "aux", "ps.txt");
	FILE* input = fopen("ps.txt", "r"); 	// open ps.txt for reading
	if(input == NULL) {	// error handling
		perror("ERROR");
		exit(-1);
	}
	// grab the last user who had -bash
	char* str = analyze(input);
	fclose(input);
	char* tok = strtok(str, " ");
	// run finger on that person
	run_command("/bin/finger", tok, "finger.txt");

	// Extract the name (i.e. first.last)
	FILE* input2 = fopen("finger.txt", "r");
	if(input2 == NULL) {	// error handling
		perror("ERROR");
		exit(-1);
	}
	char buffer[LAB6_STR_LEN];
	fgets(buffer, LAB6_STR_LEN, input2); 	// grab the first line
	tok = strtok(buffer, ":"); 		// advance through it with delimiter ':'
	tok = strtok(NULL, ":");
	tok = strtok(NULL, ": ");		// ": " gets rid of the whitespace in front of the name
	printf("Student's name: %s", tok);	// print off the name

	// now that we have the name, get when they were online
	while(fgets(buffer, LAB6_STR_LEN, input2) != NULL) { 	// for each line in the file
		// compare the line to some filter strings
		int last_online = strncmp("Last login", buffer, 10) == 0;
		int on_since = strncmp("On since", buffer, 8) == 0;
		// if either string is a match, break
		if((last_online || on_since)) { break; }
	}
	printf(buffer); // print off the buffer
	free(str);	// free the string we got earlier
	return 0;	// exit
}
