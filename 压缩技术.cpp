#include<stdio.h>
int main()
{
    int n,i,k,count=0,count2=0,flag=0;
    scanf("%d",&n);
    int a[n*n];
    while((scanf("%d",&a[i]))!=EOF)
    {
        i++;
        count++;
    }

    if(a[1]==0)
    {
        flag=1;
        k++;
    }
    for(i=1;i<=n*n;i++)
    {
        if(!flag)
        {
            printf("0");
            count2++;
            if(count2==a[k])
            {
                k++;
                count2=0;
                flag=1;
            }
        }
        else if(flag)
        {
            printf("1");
            count2++;
            if(count==a[k])
            {
                k++;
                count2=0;
                flag=0;
            }
        }
        if(i%n==0)
            printf("\n");
    }
    return 0;
}
