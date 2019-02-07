#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

//This program creates a total of 12 child processes with each parent process required to create no less than 2 or more than 3
//child processes. The program does this by having each parent process create 3 child processes. For this case every parent
//process will have children % 3 == 0 return true, the else statement is simply preliminary work on how to do the Fourth 
//Programming Task. Each parent process runs through a for loop 3 times, forking in each loop with the new child process 
//outputing in brakets its parent's ID followed by its ID so we can track the children of each process. 
//After outputing each child process recursively calls makeChild with the number of children divided by 3 since its parent process
//creates 3 children and then subtracts 1 in order to account for the parent process.
//Once children becomes 0 in the argument of makeChild it ceases to make any more children and the overall program ends since each
//previous process has already completed its task.

int main(){
	makeChild(12);						//launches recursive program makeChild to make 12 children
}

int makeChild(int children){
	if(children == 0){
		exit(0);					//exits process if told to create 0 children
	}
	int i = 0;
	if(children % 3 == 0){					//runs if children is divisible by 3
		for(i; i < 3; i++){				//runs 3 loops that each make a child process and makes recursive call
			pid_t pid = fork();
			if(pid == 0){				//child code
				printf("[%d", getppid());	//outputs process' parent ID
				printf(",%d]\n", getpid());	//outputs process' ID
				makeChild((children/3)-1);	//recursively calls makeChild to have current process make children
				exit(0);			//exits process after it has made its children
			}
		}
	}
	else{							//doesn't run in this instance
		for(i; i < 2; i++){
                        pid_t pid = fork();
                        if(pid == 0){
                                printf("[%d", getppid());
                                printf(",%d]\n", getpid());
                                if(i = 0){
					int n = (children/2)-1;
					makeChild(n);
				}
				if(i = 1){
					int n = (children/2);
                                        makeChild(n);
                                }
                                exit(0);
                        }
                }
	}



}
