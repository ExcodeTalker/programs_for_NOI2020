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

void pushup(int id)
{
    int lson=id<<1,rson=id<<1|1;
    sum[id]=sum[lson]+sum[rson];
    if (mx[lson]>mx[rson]) {mx[id]=mx[lson];cmx[id]=cmx[lson];smx[id]=max(smx[lson],mx[rson]);}
    else if (mx[lson]<mx[rson]) {mx[id]=mx[rson];cmx[id]=cmx[rson];smx[id]=max(smx[rson],mx[lson]);}
    else {mx[id]=mx[lson];cmx[id]=cmx[lson]+cmx[rson];smx[id]=max(smx[lson],smx[rson]);}
    if (mn[lson]<mn[rson]) {mn[id]=mn[lson];cmn[id]=cmn[lson];smn[id]=min(smn[lson],mn[rson]);}
    else if (mn[lson]>mn[rson]) {mn[id]=mn[rson];cmn[id]=cmn[rson];smn[id]=min(smn[rson],mn[lson]);}
    else {mn[id]=mn[lson];cmn[id]=cmn[lson]+cmn[rson];smn[id]=min(smn[lson],smn[rson]);}
}

void build(int id,int l,int r)
{
    if (l==r)
    {
        mx[id]=mn[id]=sum[id]=a[l];
        cmx[id]=cmn[id]=1;
        smx[id]=-1;smn[id]=maxd+1;
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);build(id<<1|1,mid+1,r);
    pushup(id);
}

void add(int id,int l,int r,int ql,int qr,int v)
{
    if ((l>=ql) && (r<=qr))
    {
        sum[id]+=1ll*(r-l+1)*v;tag[id]+=v;
        mx[id]+=v;mn[id]+=v;smx[id]+=v;smn[id]+=v;
        return;
    }
    int mid=(l+r)>>1;pushdown(id);
    if (ql<=mid) add(id<<1,l,mid,ql,qr,v);
    if (qr>mid) add(id<<1|1,mid+1,r,ql,qr,v);
    pushup(id);
}

void modifymax(int id,int l,int r,int ql,int qr,int v)
{
    if (mn[id]>=v) return;
    if ((l>=ql) && (r<=qr) && (smn[id]>v))
    {
        if (mx[id]==mn[id]) mx[id]=v;
        if (smx[id]==mn[id]) smx[id]=v;
        sum[id]+=1ll*(v-mn[id])*cmn[id];mn[id]=v;
        return;
    }
    int mid=(l+r)>>1;
    if (ql<=mid) modifymax(id<<1,l,mid,ql,qr,v);
    if (qr>mid) modifymax(id<<1|1,mid+1,r,ql,qr,v);
    pushup(id);
}

void modifymin(int id,int l,int r,int ql,int qr,int v)
{
    if (mx[id]<=v) return;
    if ((l>=ql) && (r<=qr) && (smx[id]>v))
    {
        if (mn[id]==mx[id]) mn[id]=v;
        if (smn[id]==mx[id]) smn[id]=v;
        sum[id]+=1ll*(v-mx[id])*cmx[id];mx[id]=v;
        return;
    }
    int mid=(l+r)>>1;pushdown(id);
    if (ql<=mid) modifymin(id<<1,l,mid,ql,qr,v);
    if (qr>mid) modifymin(id<<1|1,mid+1,r,ql,qr,v);
    pushup(id);
}

int main()
{
    n=read();
    rep(i,1,n) a[i]=read();
    build(1,1,n);
    q=read();
    while (q--)
    {
        int op=read(),x=read(),y=read(),v;
        if (op<=3) v=read();
        if (op==1) add(1,1,n,ql,qr,v);
        else if (op==2) modifymax(1,1,n,x,y,v);
        else if (op==3) modifymin(1,1,n,x,y,v);
        else if (op==4) printf("%lld\n",querysum(1,1,n,x,y));
        else if (op==5) printf("%d\n",querymax(1,1,n,x,y));
        else if (op==6) printf("%d\n",querymin(1,1,n,x,y));
    }
    return 0;
}