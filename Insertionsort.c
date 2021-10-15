#include<stdio.h>
#include<stdlib.h>
 
//1,2,3,44
void InsertionSort(int A[] , int TN)
{
    int tem,j;
    for(int i=1;i<TN;i++)
    {
       tem = A[i];
       for(j=i-1;j>=0 && tem < A[j];j--)
       {
           A[j+1] = A[j];
       } 
       A[j+1] = tem;
    }
}
int main()
{
    int A[] = {99,11,88,55,22,66,77,2,3,30,58,66,92};
    InsertionSort(A,13);
    for(int i=0;i<13;i++)
        printf("%d\t",A[i]);
}