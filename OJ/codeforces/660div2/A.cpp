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
int main(){
    int t=read();
    while(t--){
        int n=read();
        if(n==36) printf("YES\n5 6 10 15\n");
        else if(n==44) printf("YES\n6 7 10 21\n");
        else if(n==40) printf("YES\n6 10 15 9\n");
        else if(n>=31) printf("YES\n6 10 14 %d\n",n-30);
        else printf("NO\n");
    }
    return 0;
}