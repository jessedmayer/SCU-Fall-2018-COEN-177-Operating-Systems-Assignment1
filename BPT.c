#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//This program acts as a shell for launching aditional programs which the user chooses by inputing the name of the executable.
//If the user inputs exit then the shell program ends, else the shell program forks with the parent threat waiting while 
//the child thread launches the desired program.
//The child program will in turn fork and continue this process till exit is input by the user.
//This shell program should be run with  "test" as the input, which is an executable for a "hello world" program.

int main(){
	int status;
	while (1){
		char str[50];
		scanf("%s",str);			//stores user input in char array str
		if(strcmp(str, "exit")==0){		//compares user input to "exit"
			return 0;			//Exits process
		}
		if(fork() != 0){			//Parent code
			waitpid(-1,&status,0);    	//Pauses parent process till all child processes end
		}else {
			execve(str, NULL, NULL);	//Executes the executable program selected by user
			printf("Didn't run oops");	//Prints error message if couldn't launch chosen program
			return 0;			//Exits process
		}
	}

}

