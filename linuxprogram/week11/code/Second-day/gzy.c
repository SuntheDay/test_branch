#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
#include<errno.h>

int main(){
	pid_t result;
	int r_num;
	int pipe_fd[2];
	char buf_r[100];
	
	memset(buf_r,0,sizeof(buf_r));
	if(pipe(pipe_fd)<0)
	{
		printf("");
		return -1;
	}
	result=fork();
	if(result<0)
	{
		perror("");
		exit;
	}
	else if(result==0)
	{
		close(pipe_fd[1]);
		if((r_num=read(pipe_fd[0],buf_r,100))>0)
			printf("%d\n",r_num,buf_r);
		close(pipe_fd[0]);
		exit(0);
	}
	else
	{
		close(pipe_fd[0]);
		if(write(pipe_fd[1],"",10)!=1)
			printf("");
		close(pipe_fd[1]);
		waitpid(result,NULL,0);
		exit(0);
	}
}
