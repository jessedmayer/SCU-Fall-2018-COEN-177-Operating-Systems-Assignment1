#include <stdio.h>
#include <stdlib.h>

//This program creates 8 child processes without a single process creating more than two child processes
//The program does this by creating a creating a child process, the parent process then waits till the child process ends,
//so each process makes only a single child in turn. The child process increments the current number of children,
//then outputs the number of children currently followed in brakets by the parent threads ID and then the child threads ID.
//Once there are 8 children and this has been outputed, then the 8th child ends, with each previous child ending sequentially
//all the way back to the initial parent thread which in turn ends thus completing the program.

int main(){
	int children = 0;
	while(1){					//loops so that child process can fork
		pid_t pid = fork();
		int status;
		if(pid != 0){				//parent code
			waitpid(pid,&status,0);		//pauses parent till all child processes have ended
			return 0;			//exits process after its child processes have ended
		}
		if(pid  == 0){				//child code
		children = children + 1;		//increments number of children to current number
		printf("%d",children);			//outputs number of children
		printf("[%d",getppid());		//outputs current process' parent ID
		printf(",%d]\n",getpid());		//outputs current process' ID
		}

		if(children == 8){
			return 0;			//exits process once there are 8 children
		}
	}
}
