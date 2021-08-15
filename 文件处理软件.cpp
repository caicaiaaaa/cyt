#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int t;
    cin>>t>>a;
    while(t--)
    {
        int k,b,c;
        string d;
        cin>>k;
        if(k==1)
        {
           cin>>d;
           a+=d;
           cout<<a<<endl;
        }
        else if(k==2)
        {
            cin>>b>>c;
            string e=a;
            a="";
            for(int i=b;i<(e.length(),b+c);i++)
                a+=e[i];
            cout<<a<<endl;
        }
        else if(k==3)
        {
            cin>>b>>d;
            string x="";
            for(int i=0;i<b;i++)
                x+=a[i];
            x+=d;
            for(int i=b;i<a.length();i++)
                x+=a[i];
            a=x;
            cout<<a<<endl;
        }
        else if(k==4)
        {
            cin>>d;
            if(a.find(d)<100)
                cout<<a.find(d)<<endl;//findº¯Êý
            else
                cout<<-1<<endl;
        }
    }
    return 0;
}
