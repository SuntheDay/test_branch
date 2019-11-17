//调用getenv/putenv访问特定的环境变量

#include<stdio.h>

#include<stdlib.h>

int main()

{

printf("%s\n",getenv("PATH"));

return 0;

}
