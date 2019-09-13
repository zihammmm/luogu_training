/*
    P1203 [USACO1.1]坏掉的项链Broken Necklace
*/

#include <bits/stdc++.h>
using namespace std;

const int N=400;

int run(string& str, int i, int n) {
    char ch1 = str[i], ch2 = str[i + 1];
    int ans = 0;
    i+=n;
    int sum=n;
    int j;
    for ( j = 0; j < n; ++j) {
        if (ch1 == 'w') {
            ans++;
            ch1 = str[i - j];
        } else if (ch1 == str[i - j] || str[i - j] == 'w') {
            ans++;
        } else
            break;
    }
    i-=n;
    sum-=j;
    for (j = 1; j <= sum; ++j) {
        if (ch2 == 'w') {
            ans++;
            ch2 = str[i + j];
        } else if (ch2 == str[i + j] || str[i + j] == 'w') {
            ans++;
        } else
            break;
    }
    return ans;
}

int main()
{
    int n;
    string str;
    cin>>n;
    cin>>str;
    str+=str;
    int maxnum=0;
    for (int i = 0; i < n; ++i) {
        maxnum=max(maxnum,run(str,i,n));
    }
    cout<<maxnum<<endl;
    return 0;
}