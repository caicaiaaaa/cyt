#include<stdio.h>
int main()
{
    int i,n,j,m,t=0;
    int a[101];

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            for(m=0;m<n;m++)
            {
                if(j!=m&&(a[i]==a[j]+a[m]))
                   t++;
                   i++;
                   j=0;
                   m=0;
            }
    }
    printf("%d",t);
    return 0;
}
