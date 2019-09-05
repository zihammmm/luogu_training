/*
	P1387 最大正方形
	动态规划
*/

#include <bits/stdc++.h>
using namespace std;

const int N=110;
int t[N][N]={};
int dp[N][N]={};
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin>>t[i][j];
        }
    }
    int ans=0;
    for (int k = 1; k <=n ; ++k) {
        for (int i = 1; i <= m; ++i) {
            if(t[k][i])
                dp[k][i]=min(min(dp[k-1][i-1],dp[k-1][i]),dp[k][i-1])+1;
            ans=max(ans,dp[k][i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}