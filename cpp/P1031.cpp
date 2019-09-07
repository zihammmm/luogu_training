/*
	P1031 均分纸牌
*/

#include <bits/stdc++.h>
using namespace std;

const int N=110;
int f[N]={};

int main()
{
    int n;
    cin>>n;
    int sum=0;
    for (int i = 1; i <= n; ++i) {
        cin>>f[i];
        sum+=f[i];
    }
    sum/=n;
    int cnt=0;
    for (int j = 1; j <= n; ++j) {
        f[j]-=sum;
    }

    for (int k = 1; k <= n; ++k) {
        if(f[k]!=0)
        {
            f[k+1]+=f[k];
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}