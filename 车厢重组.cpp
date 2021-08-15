#include<stdio.h>
int main()
{
    int n,i,j,k=0,t;
    int a[10005];

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1;j++)
            if(a[j]>a[j+1])
               {
                   t=a[j+1];
                   a[j+1]=a[j];
                   a[j]=t;
                   k++;
               }
    printf("%d",k);
    return 0;
}
