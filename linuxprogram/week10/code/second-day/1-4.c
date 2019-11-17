#include "my.h"

static void callback1()
{
	printf("---------------callback1----------------\n");

}


static void callback2()
{
	printf("---------------callback2----------------\n");

}

static void __attribute__ ((constructor)) before_main()//C语言的构造函数
{
	printf("--------------constructor--------------\n");
}

static void __attribute__ ((destructor)) after_main()//语言的析构函数
{
	printf("--------------destructor--------------\n");
}

int main()
{
	atexit(callback1);
	atexit(callback2);
	FILE* fp;
	char buf[]={"test data!"};
	if((fp=fopen("test.dat","w+"))==NULL)
	{
		perror("failed to fopen!\n");
		return -1;
	}
	if(fputs(buf,fp)==EOF)//fputs()全缓冲
	{
		perror("failed to fputs!\n");
		return -1;
	}
	printf("printf:data from line buffer");//printf(行缓冲,,\n为行缓冲结束标志,)
	exit(0);//查看exit(0),_exit(0);return 0;是否能结束printf()的行缓冲
	//_exit(0);
	//return 0;
}









