#include<iostream>
#include<cstdio>
using namespace std;
int all;
string s;
int num[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int main()
{
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
            all+=num[s[i]-'a'];
        else if(s[i]==' ')
            all++;
    }
    printf("%d",all);
    return 0;
}
