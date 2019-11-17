#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<setjmp.h>
static jmp_buf g_stack_env;

static void fun1(void);
static void fun2(void);

static void fun1()
{
	printf("Enter=func1\n");
	fun2();
}

static void fun2()
{
	printf("Enter func2\n");
	longjmp(g_stack_env,1);
	printf("leave func2\n");
}

int main(void)
{
	if(0==setjmp(g_stack_env)){
		printf("Normal follow\n");
		fun1();
	}else{
		printf("long jump follow\n");
	}
	return 0;
}
