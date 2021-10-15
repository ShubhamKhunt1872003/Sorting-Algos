#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Mearge(int (*Arr)[2],int Left,int Mid,int Right)
{
    int i = Left,j=Mid+1,k=0;
   int B[Right-Left+1][2];
   while(i<=Mid && j<=Right)//MAin array mathi Tem array ma data sorting sathe lidho
   {
       if(Arr[i][0] < Arr[j][0])
       {
           B[k][0] = Arr[i][0];
           B[k][1] = Arr[i][1];
           i++;
       }
       else
       {
           B[k][0] = Arr[j][0];
           B[k][1] = Arr[j][1];
           j++;
       }
       k++;
   }
    while(j<=Right)//vadhelo data lidhho tem ma
    {
        B[k][0] = Arr[j][0];
        B[k][1] = Arr[j][1];
        j++;
        k++;
    }
    while(i<=Mid)//vadhelo data lidhho tem ma
    {
        B[k][0] = Arr[i][0];
        B[k][1] = Arr[i][1];
        i++;
        k++;
    }
   i=0;
   for(k=Left;k<=Right;k++)//sorted data ne main array ma nakhyo
   {
       Arr[k][0] = B[i][0];
       Arr[k][1] = B[i][1];
       i++;
   }
}
void MeargeSort(int (*Arr)[2],int Left,int Right)
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
void CoutingSort(int Array[],int Totalsize)
{
    
    int FrequenceyTable[Totalsize][2];
    memset(FrequenceyTable,0,sizeof(FrequenceyTable));
    int j=0,i,flag=0,k;
    for(i=0;i<Totalsize;i++)
    {
        flag=0;
        for(k=0;k<j;k++)
        {
            if(FrequenceyTable[k][0] == Array[i])
            {
                ++FrequenceyTable[k][1];
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            FrequenceyTable[j][0] = Array[i];
            j++;
        }
    }
    int TotalElements = j;
    for(i=0;i<TotalElements;i++)
    {
        printf("Data = %d\tFrequenecy = %d\n",FrequenceyTable[i][0],FrequenceyTable[i][1]);
    }
    MeargeSort(FrequenceyTable,0,TotalElements-1);
    printf("\n\n");
    for(i=0;i<TotalElements;i++)
    {
        printf("Data = %d\tFrequenecy = %d\n",FrequenceyTable[i][0],FrequenceyTable[i][1]);
    }
    i=0;
    for(j=0;j<TotalElements;j++)
    {
        Array[i] = FrequenceyTable[j][0];
        while(FrequenceyTable[j][1] != 0 )
        {
            i++;
            Array[i] =  FrequenceyTable[j][0];
            --FrequenceyTable[j][1];
        }
        i++;
    }
    
}

int main()
{
    int Array[] = {1,2,3,7,8,99,11,44,99,55};
    CoutingSort(Array,sizeof(Array)/4);
    printf("\n\nFinal array\n\n");
    for(int i=0;i<sizeof(Array)/4;i++)
    {
        printf("%d\t",Array[i]);
    }
}