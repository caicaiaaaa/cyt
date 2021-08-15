#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,mid,s=0,a[1000005];
int main()
{
    int i;
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);//是long long型所以注意要是%lld
            r=max(r,a[i]);//找到最长的
        }
    while(l<=r)
    {
        mid=(l+r)/2;
        s=0;
        for(i=1;i<=n;i++)
            if(a[i]>mid)//要判断mid大小是否合适
               s=s+a[i]-mid;//注意要减mid
        if(s<m)
            r=mid-1;
        else
            l=mid+1;
    }
    printf("%lld",l-1);
    return 0;
}
