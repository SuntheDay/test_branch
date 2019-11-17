//获取进程id的实现代码
//进程id:PID
//父进程id:PPID

#include<stdio.h>

#include<unistd.h>

int main()

{

printf("pid-> %d\n",getpid());

printf("ppid-> %d\n",getpid());

return 0;

 }
