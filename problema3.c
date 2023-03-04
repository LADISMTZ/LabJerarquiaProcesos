#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


int main() {
	pid_t pid;
	int m, n, fd, num1, num2, resultado;
	int arr1[]={2,4,6,8,10,12,14,16,18,20};
	int arr2[]={1,3,5,7,9,11,13,15,17,19};
	
	pid = fork();
	if (pid == 0){
		fd = creat("N.txt",777);
		n=write(fd,arr1,sizeof(arr1));
	}
	
	if (pid > 0){
		pid = fork();
		if(pid==0){
			fd = creat("M.txt",777);
			n = write(fd,arr2,sizeof(arr2));
	}
	
	if(pid>0){
		int fdN = open("N.txt",0);
		int fdM = open("M.txt",0);
		for(int i = 0; i < 10; i++){
			m=read(fdN, &num1, sizeof(int));
			close(fd);
			m=read(fdM, &num2, sizeof(int));
			close(fd);
			resultado=num1+num2;
			printf("%d + %d = %d\n", num1, num2, resultado);
			}
		}
	}
}
			
			
			
			
			
			
			
			
