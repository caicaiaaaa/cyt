#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char s[10];
    int n,k=0;
    gets(s);
    n=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
            k++;
        else if(s[i]>='A'&&s[i]<='Z')
            k++;
        else if(s[i]>='0'&&s[i]<='9')
            k++;
    }
    printf("%d",k);
    return 0;
}
