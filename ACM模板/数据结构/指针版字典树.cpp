#include <bits/stdc++.h>
using namespace std;
struct node{
    int cnt;
    node* tr[26];
};
node* rt;
const int maxn=10007;
void init(){
    rt=new node();
}
char s[maxn];
void insert(){
    node* u=rt;
    for(int i=0;s[i];i++){
        int x=s[i]-'a';
        if(u->tr[x]==NULL) u->tr[x]=new node();
        u=u->tr[x];
    }
}
int query(){
    node* u=rt;
    for(int i=0;s[i];i++){
        int x=s[i]-'a';
        if(u->tr[x]==NULL) return -1;
        u=u->tr[x];
    }
    return u->cnt;
}
