/*
	P1064 金明的预算方案
	有依赖的背包
*/

#include <bits/stdc++.h>
using namespace std;

const int N=32010;
const int M=70;
int cnt[M]={};
int num[M]={};
int f[N]={};
int V[M][M]={};
int P[M][M]={};

class node
{
public:
    int v;
    int p;
    int q;
};
int slave[M][M]={};
int main()
{
    int n,m;
    cin>>n>>m;
    int v,p,q;
    vector<node>master(m+1);
    for (int i = 1; i <= m; ++i) {
        cin>>v>>p>>q;
        master[i].v=v;
        master[i].p=p;
        master[i].q=q;

        if(q>0)
        {
            slave[q][++num[q]]=i;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (num[i])
        {
            memset(f,-1, sizeof(f));
            f[0]=0;
            for (int j = 1; j <= num[i]; ++j) {
                for (int k = n-master[i].v; k >= master[slave[i][j]].v; --k) {
                    if(f[k-master[slave[i][j]].v]!=-1)
                        f[k]=max(f[k],f[k-master[slave[i][j]].v]+master[slave[i][j]].v*master[slave[i][j]].p);
                }
            }
            for (int j = 0; j <= n-master[i].v; ++j) {
                if (f[j]!=-1)
                {
                    V[i][++cnt[i]]=j+master[i].v;
                    P[i][cnt[i]]=f[j]+master[i].v*master[i].p;
                }
            }
        }
        if(!master[i].q)
        {
            V[i][++cnt[i]]=master[i].v;
            P[i][cnt[i]]=master[i].v*master[i].p;
        }
    }
    memset(f,0, sizeof(f));
    int ans=0;
    for (int i = 1; i <= m; ++i) {
        for (int j = n; j >=0 ; --j) {
            for (int k = 1; k <= cnt[i]; ++k) {
                if(j>=V[i][k])
                    f[j]=max(f[j],f[j-V[i][k]]+P[i][k]);
            }
        }
    }
    for (int l = 0; l <= n; ++l) {
        ans=max(ans,f[l]);
    }
    cout<<ans<<endl;
    return 0;
}