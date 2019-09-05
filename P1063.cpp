/*
	P1063 能量项链
	区间DP
*/

#include <bits/stdc++.h>
using namespace std;

const int N=110;
int dp[2*N][2*N]={};
int f[2*N]={};
int sum[2*N]={};

int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>f[i];
        f[i+n]=f[i];
    }

    int maxnum=-1;
    for (int len = 2; len <= n+1; ++len) {
        for (int i = 1; len+i-1 <= 2*n; ++i) {
            int j=len+i-1;
            for (int k = i+1; k <= j-1; ++k) {
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+f[i]*f[k]*f[j]);
            }
        }
    }

    for (int l = 1; l <=n ; ++l) {
        maxnum=max(maxnum,dp[l][l+n]);
    }

    cout<<maxnum<<endl;
    return 0;
}