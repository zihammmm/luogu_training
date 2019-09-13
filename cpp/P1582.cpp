/*
    P1582 倒水
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int n)
{
    int ans=0;
    while(n>0)
    {
        if(n&1)
            ans++;
        n>>=1;
    }
    return ans;
}

int ff(int n)
{
    return n&-n;
}

int main()
{
    int n,k;
    cin>>n>>k;

    ll ans=0;
    while(f(n)>k)
    {
        int num = ff(n);
        ans+=num;
        n+=num;
    }
    cout<<ans<<endl;
    return 0;
}