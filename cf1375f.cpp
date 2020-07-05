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
const int N=100000+100;
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

#define int long long

int n,id[4],a[4];

bool cmp(int x,int y) {return a[x]<a[y];}

void ask(int x)
{
    printf("%lld\n",x);fflush(stdout);
    int pos=read();
    if (!pos) exit(0);
    a[pos]+=x;
}

signed main()
{
    n=3;
    rep(i,1,n) {a[i]=read();id[i]=i;}
    sort(id+1,id+1+3,cmp);
    puts("First");fflush(stdout);
    ask(a[id[3]]-a[id[1]]);
    sort(id+1,id+1+3,cmp);
    ask(a[id[3]]*2-a[id[1]]-a[id[2]]);
    sort(id+1,id+1+3,cmp);
    ask(a[id[2]]-a[id[1]]);
    return 0;
}
    