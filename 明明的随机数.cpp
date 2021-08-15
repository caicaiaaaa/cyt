#include<bits/stdc++.h>
using namespace std;

int a[105],b[105];

int main()
{
    int n,i,k=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    b[1]=a[1];
    for(i=2;i<=n;i++)
        if(a[i]!=a[i-1])
           b[++k]=a[i];
    printf("%d\n",k);
    for(i=1;i<=k;i++)
        printf("%d ",b[i]);
    return 0;
}
