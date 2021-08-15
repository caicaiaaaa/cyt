#include<stdio.h>

int main()
{
    int n,i=1,j;
    int a[1000];
    scanf("%d",&n);
    a[0]=n;
    while(n!=1)
    {
        if(n%2==0)
        {
            n=n/2;
        }
        else
        {
            n=n*3+1;
        }
        a[i++]=n;
    }
    for(j=i-1;j>=0;j--)
    {
        printf("%d ",a[j]);
    }
    return 0;
}
