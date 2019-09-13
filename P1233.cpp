/*
    P1233 木棍加工
*/

#include <bits/stdc++.h>
using namespace std;

const int N=5010;
int f[N]={};
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>v[i].first>>v[i].second;
        f[i]=1;
    }

    sort(v.begin()+1,v.end(),[](pair<int,int>&a, pair<int,int>&b)->bool{
        if (a.first==b.first)
            return a.second>b.second;
        return a.first>b.first;
    });
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= j; ++i) {
            if(v[j].second>v[i].second)
                f[j]=max(f[j],f[i]+1);
        }
    }

    int ans=0;
    for (int k = 1; k <= n; ++k) {
        ans=max(ans,f[k]);
    }
    cout<<ans<<endl;
    return 0;
}