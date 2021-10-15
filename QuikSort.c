#include<stdio.h>
#include<stdlib.h>
int CheckPOS(int Array[] , int L ,int R)
{

    int i = L;
    int Check = Array[R],tem;
    for(int j = L;j<R;j++)
    {
        if(Array[j]<Check)
        {
            tem = Array[j];
            Array[j] = Array[i];
            Array[i] = tem;
            i++;
        }
    }
    tem = Array[i];
    Array[i] = Array[R];
    Array[R] = tem;
    return i;
}
void QuickSort(int Array[] , int L ,int R)
{
    if(L<R)
    {
        int Tem = CheckPOS(Array,L,R);
        QuickSort(Array,L,Tem-1);
        QuickSort(Array,Tem+1,R);
    }
}
int main()
{
    int A[] = {99,11,88,55,22,66,77,2,3,30,58,66,92};
    QuickSort(A,0,12);
    for(int i=0;i<13;i++)
        printf("%d\t",A[i]);
}