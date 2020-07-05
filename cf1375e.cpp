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

int n,a[N],id[N],b[N];

bool cmp(int x,int y) 
{
    if (a[x]==a[y]) return x<y;else return a[x]<a[y];
}

bool chk()
{
    rep(i,1,n) 
        if (a[i]!=i) return 0;
    return 1;
}

int main()
{
    n=read();
    rep(i,1,n) {a[i]=read();id[i]=i;}
    sort(id+1,id+1+n,cmp);
    rep(i,1,n) a[id[i]]=i;
    int ans=0;
    rep(i,1,n) rep(j,i+1,n) ans+=(a[i]>a[j]);
    printf("%d\n",ans);
    rep(i,1,n) b[a[i]]=i;
    while (!chk())
    {
        rep(i,1,n-1)
        {
            if (b[i]>b[i+1])
            {
                printf("%d %d\n",b[i+1],b[i]);
                swap(a[b[i]],a[b[i+1]]);
                swap(b[i],b[i+1]);
                //i++;
            }
        }
    }
    //int len=ask.size();
    printf("%d\n",ans);
    return 0;
}