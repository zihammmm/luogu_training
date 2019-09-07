/*
	P1604 B进制星球
	高精度
*/

#include <bits/stdc++.h>
using namespace std;

int n=0;
char ss[36];
int getNum(char a)
{
    int i;
    for (i=0;i<36;i++)
    {
        if(ss[i]==a)
            break;
    }
    return i;
}

char getChar(int i)
{
    return ss[i];
}
int main()
{
    int i;
    for(i=0;i<10;i++)
        ss[i]=(char)(i+'0');
    while (i<36)
    {
        ss[i]=(char)(i+'A'-10);
        i++;
    }

    cin>>n;
    string str1,str2;
    cin>>str1>>str2;
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    int j=0,t=0;
    i=0;
    string ans;
    while(i<str1.size()&&j<str2.size())
    {
        t=getNum(str1[i])+getNum(str2[j])+t;
        i++;
        j++;
        ans.push_back(getChar(t%n));
        t/=n;
    }
    while(i<str1.size())
    {
        t+=getNum(str1[i]);
        i++;
        ans.push_back(getChar(t%n));
        t/=n;
    }
    while(j<str2.size())
    {
        t+=getNum(str2[j]);
        j++;
        ans.push_back(getChar(t%n));
        t/=n;
    }
    if (t>0)
    {
        ans.push_back(getChar(t));
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}