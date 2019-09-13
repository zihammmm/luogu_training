/*
    P1865 A%B problem
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000000+10;
int f[N]={};
int ans[N]={};

bool check(int l, int r, int m)
{
    return l >= 1 && r <= m;
}

void solution(int l, int r)
{
    for (int i = 2; i <= r; ++i) {
        if(!f[i])
        {
            ans[i]=ans[i-1]+1;
            for (int j = i+i; j <= r; j+=i) {
                f[j]=1;
            }
        }else{
            ans[i]=ans[i-1];
        }
    }

}

int main()
{
    int n,m;
    cin>>n>>m;

    int l,r;
    solution(1,m);
    for (int i = 0; i < n; ++i) {
        cin>>l>>r;
        if (!check(l,r,m))
        {
            cout<<"Crossing the line\n";
            continue;
        }
        cout<<ans[r]-ans[l-1]<<endl;
    }

    return 0;
}