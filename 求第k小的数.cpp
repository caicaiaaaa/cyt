#include<bits/stdc++.h>
using namespace std;

int x[5000000],k;
int main()
{
    int n;

    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&x[i]);
	nth_element(x, x+k, x+n);
	printf("%d",x[k]);


}
