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
int main(){
    int n=read();
    int ok=0;
    rep(i,1,n) a[i]=read();
    sort(a+1,a+n+1);
    rep(i,1,n-2){
        if(a[i]+a[i+1]>a[i+2]){
            cout<<a[i]<<" "<<a[i+1]<<" "<<a[i+2];
            return 0;
        }
    }
    printf("No solution");
    return 0;
}