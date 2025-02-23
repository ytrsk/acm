#include <bits/stdc++.h>
using namespace std;
const int maxn=100007;
typedef long long ll;
vector<int> g[maxn];
int n,cl,dfn[maxn],low[maxn];;
int e1,head[maxn<<1],to[maxn<<2],nex[maxn<<2];
int dcnt=0;
inline void Addedge(int u,int v){
    ++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
inline void Add(int u,int v){
    Addedge(u,v);Addedge(v,u);
}
int S[maxn],Top;
void tarjan(int u,int fa){
    dfn[u]=low[u]=++cl;S[++Top]=u;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                dcnt++;int x;
                Add(n+dcnt,u);
                do{x=S[Top--],Add(n+dcnt,x);} while(x!=v);
            }
        }
        else if(v!=fa) low[u]=min(low[u],dfn[v]);
    }
}
const int mod=1e9+7;
void init(){
    for(int i=1;i<=n;i++) g[i].clear(),dfn[i]=0;
    dcnt=cl=e1=Top=0;
    for(int i=1;i<=2*n;i++) head[i]=0;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int ans[maxn],vis[maxn];
int a[maxn],sum,Pow[maxn<<1],now;
int Pown(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}
void dfs(int u,int fa){
    Pow[u]=1;
    if(u<=n) vis[u]=1,Pow[u]=a[u];
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v^fa){
            dfs(v,u);
            Pow[u]=1LL*Pow[u]*Pow[v]%mod;
        }
    }
}
void Dfs(int u,int fa){
    if(u<=n) vis[u]=1;
    int up=1LL*now*Pown(Pow[u],mod-2)%mod;
    ans[u]=(sum+mod-now)%mod;
    if(fa) ans[u]=(ans[u]+up)%mod;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v^fa){
            Dfs(v,u);
            ans[u]=(ans[u]+Pow[v])%mod;
        }
    }
}
int main(){
    int T=read();
    while(T--){
        n=read();init();int m=read();
        for(int i=1;i<=n;i++) a[i]=read(),vis[i]=0;
        for(int i=1;i<=m;i++){
            int u=read(),v=read();
            g[u].push_back(v);g[v].push_back(u);
        }
        sum=0;
        for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,0);sum=(sum+Pow[i])%mod;
            }
        }
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                now=Pow[i];Dfs(i,0);
            }
        }
        int ed=0;
        for(int i=1;i<=n;i++) ed=(ed+1LL*i*ans[i])%mod;
        printf("%d\n",ed);
    }
    return 0;
}
