#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <complex>
using namespace std;
typedef long long ll;
const int maxn=200007;
const int mod=998244353,G=3;
int rev[maxn<<2];
ll pown(ll a,ll b){
	if(b<0){
		b=-b;a=pown(a,mod-2);
	}
	ll ans=1;
	while(b){
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
void ntt(ll *a,int n,int dft){
	for(int i=0;i<n;i++)
	if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i<<=1){
		ll wn=pown(G,dft*(mod-1)/(i*2));
		for(int k=0;k<n;k+=i<<1){
			ll wnk=1;
			for(int j=k;j<k+i;j++){
				int x=a[j],y=(wnk*a[j+i])%mod;
				a[j]=(x+y)%mod;a[j+i]=(x-y+mod)%mod;
				wnk=(wnk*wn)%mod;
			}
		}
	}
	if(dft==-1){
		int inv1=pown(n,mod-2);
		for(int i=0;i<n;i++) a[i]=(a[i]*inv1)%mod;
	}
}
void nttmul(ll *a,ll *b,int l1,int l2){
	int bit=1;
	while((1<<bit)<=l1+l2) bit++;
	for(int i=0;i<(1<<bit);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	for(int i=l1+1;i<(1<<bit);i++) a[i]=0;
	for(int i=l2+1;i<(1<<bit);i++) b[i]=0;
	ntt(a,1<<bit,1);ntt(b,1<<bit,1);
	for(int i=0;i<(1<<bit);i++) a[i]=(a[i]*b[i])%mod;
	ntt(a,1<<bit,-1);
}
ll A[maxn<<2],B[maxn<<2];
int add(int x,int y){
    return (x+y)%mod;
}
int mul(int x,int y){
    return 1LL*x*y%mod;
}
int inv[maxn],fac[maxn];
int C(int a,int b){
    if(a<b) return 0;
    return mul(fac[a],mul(inv[b],inv[a-b]));
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int s[maxn];
int main(){
    fac[0]=inv[0]=1;
    int n=read(),K=read();
    for(int i=1;i<=K;i++) fac[i]=1LL*fac[i-1]*i%mod;
    inv[K]=pown(fac[K],mod-2);
    for(int i=K-1;i;i--) inv[i]=mul(inv[i+1],i+1);
    for(int i=0;i<=K;i++){
        A[i]=mul(pown(mod-1,i),inv[i]);
        B[i]=mul(pown(i,n),inv[i]);
    }
    nttmul(A,B,K,K);
	for(int i=0;i<=10;i++)
	cout<<i<<" "<<A[i]<<endl;
	return 0;
}
