#include<stdio.h>
#include<Stdlib.h>
void ShellSort(int A[],int N)
{
    for(int gap = N/2 ; gap>0;gap /= 2) // reduce gap untile it becomes 0
    {
        for(int i = gap;i<N;i++)//gap thi start kari A[gap] and A[j-gap] vach e swapping condition applied
        {
            int Tem = A[i];
            int j;
            for(j=i;j>=gap && A[j-gap]>Tem ; j-= gap)//j reduced by gap
            {
                A[j] = A[j-gap];
            }
            A[j] = Tem;
        }
    }
}
int main()
{
    int A[] = {80,40,70,90};
    ShellSort(A,4);
    for(int i=0;i<4;i++)
    {
        printf("%d\t",A[i]);
    }
}