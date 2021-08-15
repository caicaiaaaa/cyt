#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int m,n,i,a[1000100],b[1000100];
int main()
{
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",b[i]);
    sort(a+1,a+m+1);
    int l,r,ans=0;
    for(i=1;i<=n;i++)
    {
        l=0;r=n+1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(b[mid]<=a[i])
                l=mid+1;
            else
                r=mid;
        }
        if(a[i]<=b[1])
            ans+=min(abs(a[l-1]))
    }

}
