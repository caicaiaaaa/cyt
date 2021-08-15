#include<stdio.h>

int main()
{
    int a,b;
    int c[10]={0};
    int i,k,n;

    scanf("%d %d",&a,&b);
    for(i=a;i<=b;i++)
    {
        n=i;
        while(n!=0)
        {
            k=n%10;
            c[k]++;
            n=n/10;
        }
    }
    for(i=0;i<10;i++)
        printf("%d ",c[i]);
    return 0;
}
