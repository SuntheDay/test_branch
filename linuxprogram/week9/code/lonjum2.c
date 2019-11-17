#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<setjmp.h>
static jmp_buf g_stack_env;

static void fun1(int*,int*,int*);

static void fun1(int *a,int *b,int *c)
{
	printf("Enter=func1\n");
	++(*a);
	++(*b);	
	++(*c);
	printf("fun1:a=%d,b=%d,c=%d\n",*a,*b,*c);
	longjmp(g_stack_env,1);
	printf("leave func1\n");
}

int main(void)
{
	int a=1,b=2,c=3;
	if(0==setjmp(g_stack_env)){
		printf("Normal follow\n");
		printf("1:a=%d,b=%d,c=%d\n",a,b,c);
		fun1(&a,&b,&c);
	}else{
		printf("long jump follow\n");
		printf("2:a=%d,b=%d,c=%d\n",a,b,c);
	}
	return 0;
}

