#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct Node {
    int Data;
    struct Node *Next;
}*START[10];
int FindMex(int A[],int TN)
{
    int Mex = A[0];
    for(int i=0;i<TN;i++)
    {
        if(Mex<A[i])
            Mex = A[i];
    }
    return Mex ;
}
struct Node * creatNode(void)
{
    struct Node *Tem = (struct Node *)malloc(sizeof(struct Node));
    Tem->Data = 0;
    Tem->Next = NULL;
    return Tem;
}
void RedixSort(int A[],int TN){
    int Mex = FindMex(A,TN);
    int Temint = Mex,TotalDigit = 0;
    while(Temint!=0)
    {
        Temint /= 10;
        TotalDigit++;
        
    }
    int j=0,k;
    struct Node *Tem;
    int indexCount,TemCount;
    for(int i=0;i<TotalDigit; i++)
    {
        
        for(j=0;j<TN;j++)
        {
            k = 0;
            TemCount = A[j];
            while(k != i)
            {
                TemCount = TemCount / 10;
                k++;
            }
            indexCount = TemCount % 10;
            Tem = creatNode();
            Tem->Data = A[j];
            if(START[indexCount]==NULL)
            {
                START[indexCount] = Tem;
            }
            else
            {
                struct Node *T = START[indexCount];
                while(T->Next != NULL)
                {
                    T = T->Next;
                }
                T->Next = Tem;
            }

        }
        int g=0;
        struct Node *Delete;
        for(j=0;j<10;j++)
        {
            if(START[j] != NULL)
            {
                Tem = START[j];
                while(Tem->Next != NULL)
                {
                    A[g] = Tem->Data;
                    g++;
                    Delete = Tem;
                    Tem = Tem->Next;
                    free(Delete);
                }
                A[g] = Tem->Data;
                g++;
                free(Tem);
                    
            }
        }
        for(int i=0;i<10;i++)
        {
            START[i] = NULL;
        }
    }
}
int main()
{
    for(int i=0;i<10;i++)
    {
        START[i] = NULL;
    }
    int A[]= {49,48,47,46,45,44,43,42,41,40,39,38,37};
    RedixSort(A,sizeof(A)/4);
    for(int i=0;i<(sizeof(A)/4);i++)
    {
        printf("%d\t",A[i]);
    }
}