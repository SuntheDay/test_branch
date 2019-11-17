#include "my.h"
/**
 vfork()函数功能与fork()函数功能类似不过更加彻底：内核不再给子进程创建虚拟空间，直接让子进程共享父进程的虚拟空间。当父子进程中有更改相应段的行为发生时，再为子进程相应的段创建虚拟空间并分配物理空间。在vfork()函数创建子进程后父进程会阻塞，保证子进程先行运行。

vfork()函数创建的子进程会与父进程（在调用exec函数族函数或exit()函数前）共用地址空间，此时子进程如果使用变量则会直接修改父进程的变量值。因此，vfork()函数创建的子进程可能会对父进程产生干扰。另外，如果子进程未调用exec函数族函数或exit()函数，则父子进程会出现死锁现象。

举个例子，vfork()函数创建了一个“儿子”暂时“霸占”“老爹”的房产，此时需要委屈老爹一下，让老爹歇息（阻塞）。当儿子买房了（执行exec函数族函数）或者儿子死了（执行exit()退出），就相当于分家了，此时老爹得到自己的房产。
*/


int g=10;

int main()
{
	int s=20;
	static int k=30;
	pid_t pid;
	pid=vfork();
	
	if(pid<0)
	{
		perror("vfork failed!\n");
		return -1;
	}	
	else if(pid==0)
	{
		printf("child pid=%d : \n&g=%16p\n&s=%16p\n&k=%16p\n",getpid(),&g,&s,&k);
		g=100;
		k=200;
		s=300;
		sleep(2);
		printf("child after g=%d,k=%d,s=%d",g,k,s);
		//return 0;		
		_exit(0);	
	}
	else
	{
		//sleep(2);
		printf("parent pid=%d : \n&g=%16p\n&k=%16p\n&s=%16p\n",getpid(),&g,&k,&s);
		printf("parent after g=%d,k=%d,s=%d",g,k,s);
		return 0;
		//_exit(0);	
	}

}

