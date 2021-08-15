#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j,k=0;
    int a[100000005];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n;j++)
            if(fabs(a[i]-a[i+1])==a[j])
               k++;
    }
    if(k=n-1)
        printf("Jolly");
    else
        printf("Not jolly");
    return 0;
}
