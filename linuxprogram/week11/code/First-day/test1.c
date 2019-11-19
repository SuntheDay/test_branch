
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){
	int pid1,pid,s,pid2;
	if((pid1=fork())&&(pid2=fork())<0)
	{
		perror("failed to fork@\n");
		return -1;
	}
	else if(pid1==0)
	{
		printf("%d:child is running now!\n",getpid());
	
		printf("%d:child is exit now!\n",getpid());
		while(1);
		exit(120);//退出代码为120
	}
	else
	{
		printf("%d:parent is wait zombie now!\n",getpid());
		while((pid=wait(&s))!=1){
		if(WIFEXITED(s)){
			printf("child is %d exiting normally,exit code=%d\n",pid,WEXITSTATUS(s));
		}
		else if(WIFSIGNALED(s)){
			printf("child  %d exit by signal no=%d\n",pid,WTERMSIG(s));
		}
		else{
			printf("NOT Know\n");
		}
		//wait(NULL);
		//printf("%d:parent is exit now!\n",getpid());
		//while(1);
		}
	}
	exit(0);
}
