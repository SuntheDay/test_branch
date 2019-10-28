#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<syslog.h>
#include<stdlib.h>
#include<string.h>
#define MAX 128
int chmd()
{
int c;
mode_t mode=S_IWUSR;
printf("0.0700\n 1.0400\n 2.0200\n 3.0100\n");
printf("Please input your choice(0-3):");
scanf("%d",&c);
switch(c)
{
case 0:chmod("file1",S_IRWXU);break;
case 1:chmod("file1",S_IRUSR);break;
case 2:chmod("file1",S_IWUSR);break;
case 3:chmod("file1",S_IXUSR);break;
default:printf("You have awrong choice!\n");
}
return (0);
}
