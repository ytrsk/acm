#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn];
int rt[100007],e1,a[100007],sum[2000007],ls[2000007],rs[2000007];
void pushup(int o){
	sum[o]=sum[ls[o]]+sum[rs[o]];
}
void ins(int &o,int p,int l,int r,int x){
	o=++e1;ls[o]=ls[p];rs[o]=rs[p];sum[o]=sum[p];
	int m=(l+r)>>1;
	if(l==r){
		sum[o]+=1;return;
	}
	x<=m?ins(ls[o],ls[p],l,m,x):ins(rs[o],rs[p],m+1,r,x);
	pushup(o);
}
void change(int &o,int l,int r,int x,int y){
	if(!o) o=++e1;
	if(l==r){
		sum[o]+=y;
	}
	int m=(l+r)>>1;
	if(x<=m) change(ls[o],l,m,x,y);
	else change(rs[o],m+1,r,x,y);
	pushup(o);
}
int query(int x,int y,int l,int r,int z){
	if(l==r) return a[l];
	int m=(l+r)>>1;
	if(sum[ls[y]]-sum[ls[x]]>=z) return query(ls[x],ls[y],l,m,z);
	else return query(rs[x],rs[y],m+1,r,z-(sum[ls[y]]-sum[ls[x]]));
}
int main(){

	return 0;
}