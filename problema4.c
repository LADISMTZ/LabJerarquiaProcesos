#include <stdio.h>
#include <stdlib.h>


int main(){

pid_t pid;
pid = fork();
sleep(3);

	if (pid==0){
	pid = fork();
	}else{
	pid = fork();
		if(pid==0){
		pid=fork();
	}
	
	else{
	pid=fork();
	if(pid==0){
	pid=fork();
	}
    }
}
printf("My father is: %d\n",getppid());
printf("My ID is: %d\n",getpid());
return 0;
}

