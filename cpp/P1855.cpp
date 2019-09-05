/*
	P1855 榨取kkksc03
	动态规划，背包
*/

#include <bits/stdc++.h>
using namespace std;

const int N=210;

int f[N][N]={};

int main()
{
    int n,m,t;
    cin>>n>>m>>t;
    vector<pair<int,int>>v(n+1);
    for (int i = 1; i <=n ; ++i) {
        cin>>v[i].first>>v[i].second;
    }
    for (int j = 1; j <=n ; ++j) {
        for (int i = m; i >=v[j].first ; --i) {
            for (int k = t; k >=v[j].second ; --k) {
                f[i][k]=max(f[i][k],f[i-v[j].first][k-v[j].second]+1);
            }
        }
    }
    cout<<f[m][t]<<endl;
    return 0;
}