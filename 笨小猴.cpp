#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    char a[1000];
	int prime[25]={2,3,5,7,11,13,17,
	              19,23,29,31,37,41,
			   	  43,47,53,59,61,67,
				  71,73,79,83,89,97};
    cin>>a;
    int len=strlen(a);
    sort(a,a+len);
    int k=0,sum[1000]={0};
    for(int i=0;i<len;i++)
    {
        if(a[i]==a[i+1])
           sum[k]++;
        else
           sum[k++]++;
    }
     sort(sum,sum+k);
     int i=24;
     while(i>=0)
     {
         if(prime[i--]==sum[k-1]-sum[0])
         {
             cout<<"Lucky Word"<<endl;
             cout<<sum[k-1]-sum[0];

         }
     }
     cout<<"No Answer"<<endl;
     cout<<0;
     return 0;
}
