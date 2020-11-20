#include "fns.h"

char* analyze(FILE* in) {
	// allocate memory for a buffer and a string to be saved off
	char* buffer = (char*)malloc(sizeof(char)*LAB6_STR_LEN);
	char* save_str = (char*)malloc(sizeof(char)*LAB6_STR_LEN);
	while(fgets(buffer, LAB6_STR_LEN, in) != NULL) { // for each line in the file
		// if -bash occurs in the line
		if(strstr(buffer, "-bash") != NULL) {
			// copy the contents of the buffer into save_str
			strcpy(save_str, buffer);
		}
	}
	free(buffer); // free the buffer
	return save_str; // return the string
}
