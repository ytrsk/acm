#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int g[207][207];
int main(){
    int n=read();
    for(int i=1;i<=n;i++)
    for(int k=1;k<=n;k++)
    g[i][k]=gcd(i,k);
    ll sum=0;
    for(int i=1;i<=n;i++)
    for(int k=1;k<=n;k++)
    for(int z=1;z<=n;z++)
    sum+=g[g[i][k]][z];
    cout<<sum;
    return 0;
}