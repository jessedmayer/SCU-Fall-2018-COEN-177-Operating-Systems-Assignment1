#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

//This program creates a total of 17 child processes with each parent process required to create no less than 2 or more than 3
//child processes. The program does this by having parent processes create 2 or 3 children as needed. The program does this
//recursively and creates subsequent child processes based on the children value input into makeChild. If the children value
//is divisible by 3 then it makes 3 children and then divides the children value by 3 and subtracts 1 for the parent.
//Else if the children value is divisible by 2 then it creates 2 children processes and divides by 2 and subtracts 1 for the parent.
//However if the children value is not divisible by 2 or 3 then we need to have different recursive calls for the 2 children created.
//When we divide by 2 in this case the result would not be an integer so to deal with that we have one recursive call 1 less than the
//other to deal with odd values of children that are not divisible by 3. Normally we'd want to use a floor and ceil function to do
//this but in C integer division automatically truncates to 0 so we dont need to use seal and instead of subtracting 1 for the parent
//from the ceiled recursive call we can just let it be floored automatically to account for this.Therefore each recursive call will
//create the correct number of child processes to get to 17 children overall. Before each recurive call the child process outputs
//in brakets its parent's ID followed by its ID to show us the child processes created from this program. In the case that
//the children value is not divisible by 2 or 3 the child value input in each recursive call is also displayed to show that 
//we are properly structuring the parent and child processes. Once children becomes 0 in the argument of makeChild it ceases to
//make any more children and the overall program ends since each previous process has already completed its task.

int main(){
        makeChild(17);						//launches recursive program makeChild to make 12 children
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
	else if(children % 2 == 0){				//runs if children is divisible by 2 and not 3
                for(i; i < 2; i++){				//runs 2 loops that each make a child process and makes recursive call
                        pid_t pid = fork();
                        if(pid == 0){
                                printf("[%d", getppid());
                                printf(",%d]\n", getpid());
                                makeChild((children/2)-1);
                                exit(0);
                        }
                }
        }
        else{							//runs if children is neither divisible by 2 or 3
                for(i; i < 2; i++){
                        pid_t pid = fork();
                        if(pid == 0){
                                printf("[%d", getppid());
                                printf(",%d]", getpid());
                                if(i == 0){			//runs on first loop
					int m = (children/2) - 1;//ensures recursive call will make smaller integer half of children
					printf("(%d\n",m);
                                        makeChild(m);
                                }
                                if(i == 1){			//runs on second loop
					int m = (children/2);	//ensures recursive call will make bigger integer half of children
                                        printf(",%d)\n",m);
                                        makeChild(m);
                                }
                                exit(0);
                        }
                }
        }



}  
