#include"uhead.h"
void bubbleSort(int *arr,int len)
{
    int i = 0,j = 0;
    int flag = 0;
    for(i = 0; i < len - 1; i++)
    {
        flag = 0;
        for(j = 0; j <= len - i - 2; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                arr[j] += arr[j + 1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
    return;
}


