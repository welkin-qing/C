//样例输入：
// 
//3
//
//10 30 20 40
//
//-10 17 10
//
//10 9
//
//100
//
//样例输出：
//
//20
//
//5
//
//9
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PI;
typedef pair<PI,int> PII;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int main()
{
int n;
cin>>n;
string tt;
string tmp;
getchar();
while(getline(cin,tmp))
{
stringstream ss(tmp);
bool flag=1;
int cnt=0;
int ans=0;
while(ss>>tt)
{
int t=atoi(tt.c_str());
cnt++;
if(cnt==1&&t==100)
{
flag=0;
break;
}
if(cnt<=n)
{
ans+=t;
}
}
if(flag==0)
{
break;
}
if(cnt<n)
{
    if(cnt!=0)
    cout<<(ans/cnt)<<endl;
}else
cout<<(ans/(n))<<endl;
}
return 0;
}
