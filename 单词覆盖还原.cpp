#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int boy,girl;
string s;
int main()
{
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='b') boy++;
        if(s[i]=='o'&&s[i-1]=='b')boy++;
        if(s[i]=='y'&&s[i-1]=='o')boy++;

        if(s[i]=='g')girl++;
        if(s[i]=='i'&&s[i-1]!='g')girl++;
   	    if(s[i]=='r'&&s[i-1]!='i')girl++;
   	    if(s[i]=='l'&&s[i-1]!='r')girl++;
    }
    cout<<boy<<endl<<girl<<endl;
    return 0;
}
