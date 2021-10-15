#include<stdio.h>
#include<stdlib.h>
void swap(int A[],int Index1,int Index2)
{
    int Tem = A[Index1];
    A[Index1] = A[Index2];
    A[Index2] = Tem;
}
void Heapify(int A[],int TN,int i)
{
    int Left, Right,Largest;
    Largest = i;
    Left = i*2+1;//Left child
    Right = i*2+2;//Right child
    if(Left<TN)
    {
        if(Right>=TN || A[Left] >= A[Right])//Not have right child or have but smaller than LEft child
            Largest = Left;
    }
    if((Right<TN) && (A[Left] < A[Right]))
    {
        Largest = Right;
    }
    if( (Largest != i) && (A[Largest] > A[i]))
    {
        swap(A,i,Largest);
        Heapify(A,TN,Largest);
    }
            
}
int Delete(int A[],int TN)
{
    swap(A,0,TN-1);
    Heapify(A,TN-1,0);
    return TN-1;

}
void HeapSort(int A[],int TN)
{ 
    int N = TN;
    for(int i=0;i < N;i++)
    {
        TN  = Delete(A,TN);
    }
}
int main()
{
    int A[] = {55,7,88,66,33,22,44,55};
    for(int i=((sizeof(A)/4)/2)-1;i>=0;i--)
    {
        Heapify(A,sizeof(A)/4,i);
    }
    HeapSort(A,(sizeof(A)/4));
    printf("\n\nHeap Tree\n\n");
    for(int i=0;i < sizeof(A)/4;i++)
    {
        printf("%d\t",A[i]);
    }
}