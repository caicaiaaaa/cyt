#include<stdio.h>

#define MAX 100000

int MaxSum(const int A[],int N);

int main()
{
    int N,Max;
    int A[MAX];
    scanf("%d",&N);
    for(int i = 0;i < N;i++)
        scanf("%d",&A[i]);
    Max = MaxSum(A,N);
    printf("%d",Max);
    return 0;
}


int MaxSum(const int A[],int N)
{
    int ThisSum,MaxSum,i;

    ThisSum = MaxSum = 0;
    for(i=0;i<N;i++)
    {
        ThisSum += A[i];

        if(ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
        }
        else if(ThisSum<0)
            ThisSum = 0;
    }
    return MaxSum;
}
