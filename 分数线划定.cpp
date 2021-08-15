#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int i,n,m,f;
int k[5001],s[5001],aa[5001];
bool cmp(int a,int b)
{
    if(s[a]==s[b])
        return k[a]<k[b];//成绩相等比编号
    else
        return s[a]>s[b];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d%d")
}
