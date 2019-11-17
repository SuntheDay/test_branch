#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
	char *arg[]={"./test5","123","abc","hello","ncu","edu",NULL);
	int ret;
	printf("call2:pid=%d,ppid=%d\n",getpid(),getppid());
	ret=execvp("test5",arg);
	printf("after calling! ret=%d\n",ret);
	return 0;
}
