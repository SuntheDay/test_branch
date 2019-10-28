#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<syslog.h>
#include<stdlib.h>
#include<string.h>
#include"mytest.h"
#define MAX 128

void main()
{
int fd;
int num;
int choice;
char buffer[MAX];
struct stat buf;
char* path="/bin/ls";
while(1)
{
menu(fd,num,choice,buffer,buf,path);
}
}

