#include<stdio.h>

int main()
{
    int l,n,i,j,sum=0;
    int u,v;
    int a[1005];

    scanf("%d%d",&l,&n);
    for(i=0;i<=l;i++)
        a[i]=i;
    /*while(n--)
    {
        scanf("%d%d",&u,&v);
        for(i=u;i<=v;i++)
        {
            a[i]=-1;
        }
    }*/
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        for(j=u;j<=v;j++)
            a[j]=-1;
    }
    for(i=0;i<=l;i++)
    {
        if(a[i]>=0)
            sum++;
    }
    printf("%d",sum);
    return 0;
}
