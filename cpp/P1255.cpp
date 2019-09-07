/*
	使用 P1604 B进制星球 代码
	P1255 数楼梯
	
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

    n=10;
    string str1="1",str2="2";
    int m;
    cin>>m;
    string ans;
    for (int k = 3; k <=m ; ++k) {
        if(!ans.empty())
            ans.clear();
        int j=0,t=0;
        i=0;

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
        str1=str2;
        str2=ans;

    }
    reverse(ans.begin(),ans.end());
    if(m==1)
        cout<<"1\n";
    else if (m==2)
        cout<<"2\n";
    else if (m==0)
        cout<<"0\n";
    else
        cout<<ans<<endl;
    return 0;
}