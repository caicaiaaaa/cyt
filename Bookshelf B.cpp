#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int a[200005];

int main()
{
    int n,h;
    int i,x=0,all=0;
    scanf("%d%d",&n,&h);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(i=n-1;i>=0;i--)
    {
        all=all+a[i];
        x++;
        if(all>=h)
            break;
    }
    printf("%d",x);
    return 0;
}
