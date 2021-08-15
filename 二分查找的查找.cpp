#include<stdio.h>
int main()
{
    int n,m,i=1,j=1;
    int a[100000];

    scanf("%d",&n);
    scanf("%d",&m);

    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    while(m--)
    {
        int key;
        scanf("%d",&key);
        int l=1,r=n+1,ans=-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(a[mid]==key)
            {
                r=mid;
                ans=mid;
            }
            else if(a[mid]<key)
                l=mid+1;
            else
                r=mid;
        }
        if(a[ans]!=key)
           ans=-1;
         printf("%d ",ans);
    }
    return 0;
}

























