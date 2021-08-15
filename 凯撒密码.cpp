#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    int n;
    cin>>n;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]+n>122)
            a[i]=a[i]-26+n;
        else
            a[i]=a[i]+n;
    }
    cout<<a;
    return 0;
}
