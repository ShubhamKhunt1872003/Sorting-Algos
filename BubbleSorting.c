#include<stdio.h>
#include<stdlib.h>
void BubbleSort(int A[] , int N);
int main()
{
    int A[] = {99,11,88,55,22,66,77,2,3,30,58,66,88};
    BubbleSort(A,sizeof(A)/4);
    for(int i=0;i<sizeof(A)/4;i++)
        printf("%d\t",A[i]);

}
void BubbleSort(int A[] , int N)
{
    int i,tem;
    for(int Round= 1;Round<N;Round++)
    {
        for(i=0;i<N-Round;i++)
        {
            if(A[i]>A[i+1])
            {
                tem = A[i];
                A[i] = A[i+1];
                A[i+1] = tem;
            }
        }
    }

}