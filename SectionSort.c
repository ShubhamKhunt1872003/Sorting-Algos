#include<stdio.h>
#include<stdlib.h>
#define N 10
int FindMIN(int A[],int I,int TN)
{
    int LOC=I,j,MIN=A[I];
    for(j=I+1;j<TN;j++)
    {
        if(A[j] < MIN)
        {
            MIN=A[j];
            LOC = j;
        }
    }
    return LOC;
}
int main()
{
    int A[] = {10,18,9,50,55,177,66,22,57,52},tem;
    for(int i=0;i<N-1;i++)
    {
        int LOC = FindMIN(A,i,10);
        tem = A[LOC];
        A[LOC] = A[i];
        A[i] = tem;
    }
    for(int i=0;i<N;i++)
    {
        printf("%d\t",A[i]);
    }
}