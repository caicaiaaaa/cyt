#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,mid,s=0,a[1000005];
int main()
{
    int i;
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);//��long long������ע��Ҫ��%lld
            r=max(r,a[i]);//�ҵ����
        }
    while(l<=r)
    {
        mid=(l+r)/2;
        s=0;
        for(i=1;i<=n;i++)
            if(a[i]>mid)//Ҫ�ж�mid��С�Ƿ����
               s=s+a[i]-mid;//ע��Ҫ��mid
        if(s<m)
            r=mid-1;
        else
            l=mid+1;
    }
    printf("%lld",l-1);
    return 0;
}
