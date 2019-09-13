/*
    P2123 皇后游戏
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class node{
public:
    int a,b,d;
public:
    node(int aa, int bb){
        a=aa;
        b=bb;
        d=a-b;
        if(d)
            d/=abs(d);
    }
};

int main()
{
    int t;
    cin>>t;
    int a,b;
    int n;
    for (int i = 0; i < t; ++i) {
        cin>>n;
        vector<node>v;
        for (int j = 0; j < n; ++j) {
            cin>>a>>b;
            v.emplace_back(a,b);
        }
        sort(v.begin(),v.end(),[](node& x, node& y)->bool{
           if(x.d!=y.d)
               return x.d<y.d;
           if(x.d<=0)
               return x.a<y.a;  // 注意没有等号
           else
               return x.b>y.b;
        });
        ll c=0,aa=0;
        for (int k = 0; k < n; ++k) {
            aa+=v[k].a;
            c=max(c,aa)+v[k].b;
        }
        cout<<c<<endl;
    }
    return 0;
}