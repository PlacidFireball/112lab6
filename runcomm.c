#include "fns.h"

void run_command(const char* command, const char* arg, const char* f_name) {
	// handle null arguments
	if(command == NULL || f_name == NULL || arg == NULL) {
		return;
	}
	// fork so we can run execl()
	if(fork() == 0) {
		int fd;	// the file descriptor
		// attempt to open the file, f_name
		if((fd = open(f_name, O_RDWR|O_CREAT, S_IRUSR|S_IWUSR)) != -1) {
			dup2(fd, STDOUT_FILENO);	// writes whatever STDOUT gets to the file
			close(fd);
			execl(command, command, arg, NULL); // execute the desired command
		}
	}
	// wait for the child process to finish
	wait(NULL);
	return;
}
