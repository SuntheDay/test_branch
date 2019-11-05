#include<stdio.h>
#include<unistd.h>
int main()
{
	char*args[]={"/home/xiedonghao/rlk/test3",NULL};
	printf("系统分配的进程号是：%d\n",getpid());
	if(execve("/home/xiedonghao/rlk/test3",args,NULL)<0)
		perror("用exeve创建进程出错");
	return 1;
}
