/*
	P1541 乌龟棋
	动态规划
*/

#include <bits/stdc++.h>
using namespace std;

const int M=45;
const int N=360;
int f[N]={};
int num[5]={};
int dp[M][M][M][M]={};

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
        cin>>f[i];
    }
    int x;
    for (int j = 0; j < m; ++j) {
        cin>>x;
        num[x]++;
    }
    dp[0][0][0][0]=f[1];

    for (int i = 0; i <= num[1]; ++i) {
        for (int j = 0; j <= num[2]; ++j) {
            for (int k = 0; k <= num[3]; ++k) {
                for (int l = 0; l <= num[4]; ++l) {
                    int g=i+j*2+k*3+l*4+1;
                    if (i)
                        dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l]+f[g]);
                    if (j)
                        dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j-1][k][l]+f[g]);
                    if (k)
                        dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k-1][l]+f[g]);
                    if (l)
                        dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k][l-1]+f[g]);
                }
            }
        }
    }

    cout<<dp[num[1]][num[2]][num[3]][num[4]]<<endl;
    return 0;
}