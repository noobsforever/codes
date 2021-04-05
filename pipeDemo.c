#include<stdio.h>
#include<unistd.h>


int main(void) {
	int pipefd[2];
	char buffer[15];
	pipe(pipefd);
	int pid=fork();
	

	if(pid==0){
		fflush(stdin);
		printf("In Child Process Write Now\n");
		write(pipefd[1],"Hellow Mr.Linux",15);
	}
	else if(pid>0){
		sleep(5);
		fflush(stdin);
		printf("In Parent Process Right Now\n");
		read(pipefd[0],buffer,sizeof(buffer));
		write(1,buffer,sizeof(buffer));
		printf("\n");
	}
	else{
		printf("Error In Creating Child Process\n");
	}
	if(pid==0){
		wait();
	}
}
	