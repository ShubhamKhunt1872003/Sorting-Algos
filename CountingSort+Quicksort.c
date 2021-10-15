#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int CheckPOS(int (*Array)[2] , int L ,int R)
{

    int i = L;
    int Check = Array[R][0],tem;
    for(int j = L;j<R;j++)
    {
        if(Array[j][0]<Check)
        {
            tem = Array[j][0];
            Array[j][0] = Array[i][0];
            Array[i][0] = tem;

            tem = Array[j][1];
            Array[j][1] = Array[i][1];
            Array[i][1] = tem;
            i++;
        }
    }
    tem = Array[i][0];
    Array[i][0] = Array[R][0];
    Array[R][0] = tem;

    tem = Array[i][1];
    Array[i][1] = Array[R][1];
    Array[R][1] = tem;
    return i;
}
void QuickSort(int (*Array)[2] , int L ,int R)
{
    if(L<R)
    {
        int Tem = CheckPOS(Array,L,R);
        QuickSort(Array,L,Tem-1);
        QuickSort(Array,Tem+1,R);
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
    // for(i=0;i<TotalElements;i++)
    // {
    //     printf("Data = %d\tFrequenecy = %d\n",FrequenceyTable[i][0],FrequenceyTable[i][1]);
    // }
    QuickSort(FrequenceyTable,0,TotalElements-1);
    printf("\n\n");
    // for(i=0;i<TotalElements;i++)
    // {
    //     printf("Data = %d\tFrequenecy = %d\n",FrequenceyTable[i][0],FrequenceyTable[i][1]);
    // }
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
    int Array[] = {99,88,44,22,55,88,1,7,2,1,8,66,55,7,1,66,66,88,77,55};
    CoutingSort(Array,sizeof(Array)/4);
    printf("\n\nFinal array\n\n");
    for(int i=0;i<sizeof(Array)/4;i++)
    {
        printf("%d\t",Array[i]);
    }
}