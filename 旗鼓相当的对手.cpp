#include <stdio.h>
#include<math.h>

int main()
{
    int i,j,n,all=0;
    int a[1000][5],sum[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i][0]);
        scanf("%d",&a[i][1]);
        scanf("%d",&a[i][2]);
        sum[i]=a[i][0]+a[i][1]+a[i][2];
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(fabs(a[i][0]-a[j][0])<=5&&fabs(a[i][1]-a[j][1])<=5&&fabs(a[i][2]-a[j][2])<=5&&fabs(sum[i]-sum[j])<=10)
               all++;
        }
    }
    printf("%d",all);

    return 0;
}
