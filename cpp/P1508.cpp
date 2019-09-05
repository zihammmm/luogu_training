/*
	P1508 Likecloud-吃、吃、吃
	动态规划
*/

#include <bits/stdc++.h>
using namespace std;

int table[210][210]={};

int main()
{
    int m,n;
    cin>>n>>m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin>>table[i][j];
            table[i][j]+=max(max(table[i-1][j-1],table[i-1][j]),table[i-1][j+1]);
        }
    }

    int maxnum=max(max(table[n][m/2],table[n][m/2+1]),table[n][m/2+2]);
    cout<<maxnum<<endl;
    return 0;
}