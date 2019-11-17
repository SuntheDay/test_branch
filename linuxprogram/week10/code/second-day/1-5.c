#include "my.h"
/**
*在使用fork()函数创建子进程的时候，我们的头脑内始终要有一个概念：在调用fork()函数前是一个进程在执行这段代码，而调用fork()函数后就变成了两个进程在执行这段代码。两个进程所执行的代码完全相同，都会执行接下来的if-else判断语句块。当子进程从父进程内复制后，父进程与子进程内都有一个"pid"变量：在父进程中，fork()函数会将子进程的PID返回给父进程，即父进程的pid变量内存储的是一个大于0的整数；而在子进程中，fork()函数会返回0，即子进程的pid变量内存储的是0；如果创建进程出现错误，则会返回-1，不会创建子进程。
fork()函数一般不会返回错误，若fork()函数返回错误，则可能是当前系统内进程已经达到上限，或者内存不足。

注意：父子进程的运行先后顺序是完全随机的（取决于系统的调度），也就是说在使用fork()函数的默认情况下，无法控制父进程在子进程前进行还是子进程在父进程前进行。
*/
int g=10;

int main()
{
	int s=20;
	static int k=30;
	int status;
	pid_t pid;
	pid=fork();
	
	if(pid<0)//若返回值为-1(即<0)，表示创建子进程失败
	{
		perror("fork failed!\n");
		return -1;
	}	
	else if(pid==0)//若返回值为0，表示该部分代码为子进程

	{
		printf("child pid=%d : \n&g=%16p\n&s=%16p\n&k=%16p\n",getpid(),&g,&s,&k);
		g=100;
		k=200;
		s=300;
		//sleep(2);
		//execl("./proc1","proc1",NULL);
		printf("child after g=%d,k=%d,s=%d",g,k,s);
		//return 0;		
		//_exit(0);
		_exit(12);	
	}
	else//若返回值>0，则表示该部分为父进程代码，返回值是子进程的PID
	{
		//sleep(2);
		wait(&status);
		printf("child _exit code=%d\n",WEXITSTATUS(status));
		printf("parent pid=%d : \n&g=%16p\n&k=%16p\n&s=%16p\n",getpid(),&g,&k,&s);
		printf("parent after g=%d,k=%d,s=%d",g,k,s);
		return 0;
		//_exit(0);	
	}

}



