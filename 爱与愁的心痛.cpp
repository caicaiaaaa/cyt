#include<stdio.h>
int main()
{
    int n,m,i,j;
    int sum=0,min=0;
    int a[100];

    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<m;i++)
        min=min+a[i];
    for(i=0;i<n-m;i++)//注意这里的n-m
    {
        sum=0;
        for(j=i;j<i+m;j++)
            sum=sum+a[j];
        if(sum<min)
            min=sum;
    }
    printf("%d",min);
    return 0;
}
