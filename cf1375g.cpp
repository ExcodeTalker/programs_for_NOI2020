#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<bitset>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N=200000+100;
const db pi=acos(-1.0);
#define lowbit(x) ((x)&(-x))
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define go(u,i) for (register int i=head[u],v=sq[i].to;i;i=sq[i].nxt,v=sq[i].to)
#define fir first
#define sec second
#define mkp make_pair
#define pb push_back
#define maxd 998244353
#define eps 1e-8
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

inline ll readll()
{
    ll x=0;int f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

struct node{int to,nxt;}sq[N<<1];
int all=0,head[N];

int n,cnt;

void addedge(int u,int v)
{
    all++;sq[all].to=v;sq[all].nxt=head[u];head[u]=all;
}

void dfs(int u,int fu,int c)
{
    if (c) cnt++;
    go(u,i)
    {
        if (v==fu) continue;
        dfs(v,u,c^1);
    }
}

int main()
{
    n=read();
    rep(i,1,n-1)
    {
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
    }
    dfs(1,0,0);
    cnt=min(cnt,n-cnt);
    printf("%d",cnt-1);
    return 0;
}