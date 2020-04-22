// I pledge my honor that I have abided by the Stevens Honor System - Aparajita Rana

//#include based on functions in the presentation
#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

//child process -> just print the statement
void childprocess(void){
	printf("hello from child\n");
}

//parent process -> while loop to wait for child
void parentprocess(void){
		while(1){
			sleep(5);
			printf("hello from parent\n");
		}
}

int main(void){
	
	//create new process
	pid_t  pid;
    pid = fork();
    
    //determine whether error, child, or parent
    if (pid < 0){
    	perror("Error in PID");
		return -1;
    }
    else if (pid == 0){
    	childprocess();
    }
    else{
    	//print the process ID of the child
     	printf("The process ID of the child: %d\n",pid);
     	wait(&pid);
        parentprocess();
        //WIFEXITED(pid);
        return 1;

	}
	return 1;
}
