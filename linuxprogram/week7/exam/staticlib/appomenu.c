
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

void menu(int fd,int num,int choice,char *buffer,struct stat buf,char* path)
{
char*  argv[4]={"ls","-l","file1",NULL};
printf("****************************\n");
printf("0.退出\n");
printf("1.创建新文件\n");
printf("2.写文件\n");
printf("3.读文件\n");
printf("4.修改文件权限\n");
printf("5.查看当前文件的权限修改文件权限\n");
printf("****************************\n");
printf("Please input your choice(0-6):");
scanf("%d",&choice);
switch(choice)
{
case 0:close(fd);
exit(0);
case 1: 
fd=open("file1",O_RDWR|O_TRUNC|O_CREAT,0750);
if(fd==-1)
printf("File Create Failed!\n");
else
printf("fd=%d\n",fd);
break;
case 2:
num=read(0,buffer,MAX);
write(fd,buffer,num);
break;
case 3:
read(fd,buffer,MAX);
write(1,buffer,num);
break;
case 4:
chmd();
printf("Change mode success!\n");
break;
case 5:
execv(path,argv);
break;
default:
printf("You have a wrong choice!\n");
}
}
