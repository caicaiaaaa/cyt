#include<bits/stdc++.h>
using namespace std;
struct dis
{
    int x,y,z;
};
bool cmp(dis a,dis b)
{
    return a.z<b.z;
}
int main()
{
    int n;
    cin>>n;
    dis distance[n];
    for(int i=0;i<n;i++)
        cin>>distance[i].x>>distance[i].y>>distance[i].z;
    sort (distance,distance+n,cmp);
    double ans=0;
    for(int i=0;i<n-1;i++)
        ans+=sqrt(pow(distance[i].x-distance[i+1].x,2)+pow(distance[i].y-distance[i+1].y,2)+pow(distance[i].z-distance[i+1].z,2));
    cout<<fixed<<setprecision(3)<<ans;
    return 0;
}
