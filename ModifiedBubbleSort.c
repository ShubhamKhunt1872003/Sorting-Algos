#include<stdio.h>
#include<stdlib.h>
void BubbleSort(int A[] , int N);
int main()
{
    int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    BubbleSort(A,13);
    for(int i=0;i<13;i++)
        printf("%d\t",A[i]);

}
void BubbleSort(int A[] , int N)
{
    int i,tem,flag;
    for(int Round= 1;Round<N;Round++)
    {
        flag=0;
        for(i=0;i<N-Round;i++)
        {
            if(A[i]>A[i+1])
            {
                flag=1;
                tem = A[i];
                A[i] = A[i+1];
                A[i+1] = tem;
            }
        }
        if(flag==0)
        {
            //printf("\n%d\n",Round);
            return;
        }
    }

}