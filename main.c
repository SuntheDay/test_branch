#include"uhead.h"
int cmp(const void *a,const void *b){

return (*(int*)a-*(int*)b);
}

int main()
{
  int a[UNUMBER] = {};
  urand(a,UNUMBER);
  //bubbleSort(a,UNUMBER);
  qsort(a,UNUMBER,sizeof(a[0]),&cmp);
  show(a,UNUMBER);
  return 0;
}   
