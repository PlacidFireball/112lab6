#ifndef FNS_H
#define FNS_H

// libraries to help analyze data
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// libraries to grab data from the OS
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

// default string length
#define LAB6_STR_LEN 2000

// runs a linux command and stores whatever the OS outputs to f_name
void run_command(const char* command, const char* arg, const char* f_name);
// analyzes the contents of a file to grab the last occurence of a string with -bash in it
char* analyze(FILE* in);
#endif
