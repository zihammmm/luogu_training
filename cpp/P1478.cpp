/*
    P1478 P1478 陶陶摘苹果（升级版）
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s;
    int a,b;
    cin>>n>>s;
    cin>>a>>b;
    vector<pair<int,int>>v(n+1);

    for (int i = 1; i <= n; ++i) {
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin()+1, v.end(),[](pair<int,int>&a, pair<int,int>&b)->bool{
        if (a.second==b.second)
            return a.first<b.first;
        return a.second<b.second;
    });

    int num=0;
    for (int i = 1; i <= n && s > 0; ++i) {
        if(s<v[i].second)
            break;
        if (v[i].first<=a+b)
        {
            num++;
            s-=v[i].second;
        }
    }
    cout<<num<<endl;
    return 0;
}