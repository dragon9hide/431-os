#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>

int main(int argc, char* argv[]) {
	if (argc < 1) {
        execlp("/usr/bin/wget", "wget", "index.html", NULL);;
        return 0;
  }
  for(int i = 1; i < argc; i++){	
		int pid = fork();
		if (pid > 0) {
			// Parent
			printf("waiting for web download \n");
			int child_pid = wait(NULL);
			printf("webpage downloaded \n");
		}
		else if (pid == 0) {
			execlp("/usr/bin/wget", "wget", argv[i], NULL);
			exit(0);
		}
  }
  printf("\n");
	return 0;
}