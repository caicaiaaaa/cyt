#include<stdio.h>
int main()
{
    int n = 0,i,sum = 0;
    int a[1000];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            if(a[j]<a[i])
                sum++;
        }
        printf("%d ",sum);
        sum = 0;
    }
    return 0;
}
