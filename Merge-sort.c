#include<stdio.h>
void Mearge(int Arr[],int Left,int Mid,int Right)
{
    int i = Left,j=Mid+1,k=0;
   int B[Right-Left+1];
   while(i<=Mid && j<=Right)//MAin array mathi Tem array ma data sorting sathe lidho
   {
       if(Arr[i] < Arr[j])
       {
           B[k] = Arr[i];
           i++;
       }
       else
       {
           B[k] = Arr[j];
           j++;
       }
       k++;
   }
    while(j<=Right)//vadhelo data lidhho tem ma
    {
        B[k] = Arr[j];
        j++;
        k++;
    }
    while(i<=Mid)//vadhelo data lidhho tem ma
    {
        B[k] = Arr[i];
        i++;
        k++;
    }
   i=0;
   for(k=Left;k<=Right;k++)//sorted data ne main array ma nakhyo
   {
       Arr[k] = B[i];
       i++;
   }
}
void MeargeSort(int Arr[],int Left,int Right)
{
    if(Left<Right)
    {
        int Mid;
        Mid = (Left+Right)/2;
        MeargeSort(Arr,Left,Mid);
        MeargeSort(Arr,Mid+1,Right);
        Mearge(Arr,Left,Mid,Right);
    }
}
int main()
{
    int A[] = {11,9,15,3,55,88,44,11,22,33,44,55};
    MeargeSort(A,0,11);
    for(int i=0;i<12;i++)
        printf("%d\t",A[i]);
}