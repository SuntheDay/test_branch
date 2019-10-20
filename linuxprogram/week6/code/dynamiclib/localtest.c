#include"dylib.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[5];
	init(a,5);
	show(a,5);
	printf("max=%d\n",max(a,5));
	printf("sum=%d\n",sum(a,5));
    return 0;
}
	
