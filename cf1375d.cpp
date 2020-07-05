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
const int N=1000+100;
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

int n,a[N],cnt[N];
vi ans;

int mex()
{
    rep(i,0,n) cnt[i]=0;
    rep(i,0,n-1) cnt[a[i]]++;
    rep(i,0,n) if (!cnt[i]) return i;
}

bool chk()
{
    rep(i,0,n-1) 
        if (a[i]!=i) return 0;
    return 1;
}

int main()
{
    int T=read();
    while (T--)
    {
        n=read();
        rep(i,0,n-1) a[i]=read();
        ans.clear();
        while (!chk())
        {
            int x=mex();
            if (x==n) 
            {
                rep(i,0,n-1)
                {
                    if (a[i]!=i) 
                    {
                        ans.pb(i);a[i]=x;break;
                    }
                }
            }
            else
            {
                ans.pb(x);a[x]=x;
            }
        }
        int len=ans.size();
        printf("%d\n",len);
        rep(i,0,len-1) printf("%d ",ans[i]+1);puts("");
    }
    return 0;
}
            