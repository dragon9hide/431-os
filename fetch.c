#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	for(int i = 1; i < argc; i++){	
		int pid = fork();
		if (pid > 0) {
			// Parent
			printf("waiting for web download");
			int child_pid = wait(NULL);
			printf("webpage downloaded");
		}
		else if (pid == 0) {
			char url[] = argv[i];
			execlp("/usr/bin/wget", "wget", url, NULL);
			exit(0);
		}
	return 0;
}