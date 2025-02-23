#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
const int maxn=100007;
const double eps=1e-7;
#define ppb pair<pair<point,point>,bool>
#define pp pair<point,point>
struct point{
	double x,y;
	point(double x=0.0,double y=0.0):x(x),y(y){
	}
	double operator ^ (point a){
		return x*a.y-y*a.x;
	}
	double operator * (point a){
		return x*a.x+y*a.y;
	}
	inline point operator - (point a){
		return point(x-a.x,y-a.y);
	}
	inline point operator + (point a){
		return point(x+a.x,y+a.y);
	}
	inline point operator * (double a){
        return point(x*a,y*a);
	}
    inline bool operator == (point a){
        return fabs(x-a.x)<eps&&fabs(y-a.y)<eps;
	}
	inline bool operator < (point a){
        if(fabs(y-a.y)<eps) return x<a.x;
        return y<a.y;
	}
	void print(){
        cout<<x<<" "<<y<<" ";
	}
}p[maxn],s;
bool equal0(double x){
    return fabs(x)<eps;
}
bool equal_num(double x,double y){
    return fabs(x-y)<eps;
}
typedef point vec;
inline double length(point a){
    return sqrt(sqr(a.x)+sqr(a.y));
}
inline bool parallel(point a,point b,point c,point d){
    return equal0((b-a)^(d-c));
}
inline double dis(point a,point b){
    return length(a-b);
}
inline double dot(point a,point b,point c){
    return (a-c)*(b-c);
}
inline double mul(point a,point b,point c){
    return (a-c)^(b-c);
}
inline bool cmp(point a,point b){
    if(fabs(mul(a,b,s))<eps) return dis(a,s)<dis(b,s);
    else return mul(a,b,s)>0;
}
inline int sign(double x){
    if(fabs(x)<eps) return 0;
    else if(x>0) return 1;
    else return -1;
}
int top;point q[maxn];
inline void sort_by_angle1(point *p,int n){
    int pos=1;
    for(int i=2;i<=n;i++){
        if(p[i].y+eps<p[pos].y||fabs(p[i].y-p[pos].y)<eps&&p[i].x<p[pos].x) pos=i;
    }
    swap(p[1],p[pos]);s=p[1];
    sort(p+2,p+n+1,cmp);
}
inline void graham(point *p,int n){
    sort_by_angle1(p,n);
    top=0;
    if(n==1){
        q[++top]=p[1];return;
    }
    else if(n==2){
        q[++top]=p[1];q[++top]=p[2];return;
    }
    q[++top]=p[1];q[++top]=p[2];
    for(int i=3;i<=n;i++){
        while(top>=2&&mul(p[i],q[top],q[top-1])>-eps) top--;
        q[++top]=p[i];
    }
}
inline double tri_s(point a,point b,point c){
	return fabs((a-b)^(c-b))/2;
}
void sort_by_angle2(point *p,int n,point a){
    s=a;
    sort(p+1,p+n+1,cmp);
}
//intersection of segment and line
bool intersect_line_segment(point a,point b,point c,point d){
    double x=mul(b,c,a)*mul(b,d,a);
    return x<eps;
}
double dis_point_to_line(point a,point b,point c){
    double x=mul(b,a,c);
    return fabs(x)/length(b-c);
}
bool online(point a,point b,point c){
    return equal0(mul(c,b,a));
}
bool onsegment(point a,point b,point c){
    return online(a,b,c)&&dot(b,c,a)<eps;
}
bool onsegment_spec(point a,point b,point c){
    return online(a,b,c)&&dot(b,c,a)<-eps;
}
bool intersect_segment_spec(point a,point b,point c,point d){
    double x1=mul(b,c,a),x2=mul(b,d,a);
    double x3=mul(d,a,c),x4=mul(d,b,c);
    if(equal0(x1)&&equal0(x2)) return onsegment_spec(a,c,d)||onsegment_spec(b,c,d);
    else if(sign(x1*x2)<0&&sign(x3*x4)<0) return true;
    else return false;
}
bool intersect_segment(point a,point b,point c,point d){
    double x1=mul(b,c,a),x2=mul(b,d,a);
    double x3=mul(d,a,c),x4=mul(d,b,c);
    if(equal0(x1)&&equal0(x2)) return onsegment(a,c,d)||onsegment(b,c,d);
    else if(sign(x1*x2)>0||sign(x3*x4)>0) return false;
    else return true;
}
point get_intersect_point(point p1,point p2,point p3,point p4){
    return p1+(p2-p1)*(((p1-p3)^(p4-p3))/((p4-p3)^(p2-p1)));
}
//probably some eps problem===================================
inline ppb get_intersect_segment(point a,point b,point c,point d){
    if(onsegment(a,c,d)||onsegment(b,c,d)){
        if(b<a) swap(a,b);
        if(d<c) swap(c,d);
        point x,y;
        if(onsegment(c,a,b)) x=c;else x=a;
        if(onsegment(d,a,b)) y=d;else y=b;
        return make_pair(make_pair(x,y),true);
    }
    else return make_pair(make_pair(0,0),false);
}
inline point project_point(point p,point a,point b){
    point ans;
    double u=((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
    u = ((b.x-a.x)*(b.x-p.x)+(b.y-a.y)*(b.y-p.y))/u;
    ans.x=u*a.x+(1-u)*b.x;
    ans.y=u*a.y+(1-u)*b.y;
    return ans;
}
inline ppb project_segment(point a,point b,point c,point d){
    point x=project_point(c,a,b),y=project_point(d,a,b);
    return get_intersect_segment(a,b,x,y);
}
inline pp project_line(point a,point b,point c,point d){
    point x=project_point(c,a,b),y=project_point(d,a,b);
    return make_pair(x,y);
}
//==========================================================
struct segment{
    point a,b;double ang;
    double angle(){
        return atan2(b.y-a.y,b.x-a.x);
    }
    segment(point a=point(),point b=point()):a(a),b(b){
        ang=angle();
    }
};
struct polygon{
    segment s[21];
    int num;
};
struct circle{
    point o;
    double r;
};
int circle_to_line(circle a,point b,point c){
    double x=dis_point_to_line(a.o,b,c);
    if(fabs(x-a.r)<eps) return 0;
    else if(x<a.r) return 1;
    else return -1;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
bool cmp_seg(segment a,segment b){
    return fabs(a.ang-b.ang)<eps?((a.b-a.a)^(b.b-a.a))<eps:a.ang<b.ang;
}
bool point_in_poly(point a,point *p,int n){
    for(int i=1;i<n;i++){
        if(mul(p[i],p[i+1],a)<-eps) return false;
    }
    return mul(p[n],p[1],a)>-eps;
}
inline void clockwise(point *p,int n){
    double ans=0;
    for(int i=2;i<=n;i++) ans+=mul(p[i-1],p[i],p[1]);
    if(ans<0) reverse(p+1,p+n+1);
}
double poly_area(point *p,int n){
    double ans=0;
    for(int i=1;i<=n;i++) ans+=p[i]^p[i%n+1];
    return fabs(0.5*ans);
}
segment qs[maxn];point qp[maxn];
inline bool SI(segment *s,int n,point *res,int &m){
    sort(s+1,s+n+1,cmp_seg);
    int ql=1,qr=0;
    qs[++qr]=s[1];
    for(int i=2;i<=n;i++){
        if(fabs(s[i].ang-s[i-1].ang)>eps){
            while(ql<qr&&mul(s[i].b,qp[qr-1],s[i].a)<-eps) --qr;
            while(ql<qr&&mul(s[i].b,qp[ql],s[i].a)<-eps) ++ql;
            qp[qr]=get_intersect_point(qs[qr].a,qs[qr].b,s[i].a,s[i].b);
            qs[++qr]=s[i];
            if(parallel(qs[qr-1].a,qs[qr-1].b,qs[qr].a,qs[qr].b))
            return false;
        }
    }
    while(ql<qr&&mul(qs[ql].b,qp[qr-1],qs[ql].a)<-eps) --qr;
    while(ql<qr&&mul(qs[qr].b,qp[ql],qs[qr].a)<-eps) ++ql;
    if(qr<=ql+1) return false;
    qp[qr]=get_intersect_point(qs[ql].a,qs[ql].b,qs[qr].a,qs[qr].b);
    m=0;for(int i=ql;i<=qr;i++) res[++m]=qp[i];
    return true;
}
char S[30];
segment seg[maxn];point res[maxn];
int main(){
    point now=point(0,0);
    seg[1]=segment(point(0,0),point(10,0));
    seg[2]=segment(point(10,0),point(10,10));
    seg[3]=segment(point(10,10),point(0,10));
    seg[4]=segment(point(0,10),point(0,0));
    double x,y;
    int m;
    int ok=0,cnt=0;
    while(scanf("%lf%lf",&x,&y)==2){
        scanf("%s",S+1);
        if(ok){
            printf("0.00\n");continue;
        }
        if(S[1]=='S'){
            ok=1;
            printf("0.00\n");continue;
        }
        else if(S[1]=='C'){
            point M=point((now.x+x)/2,(now.y+y)/2);
            point D=point(x,y)-now;
            point Z=point(-D.y,D.x);
            ++cnt;
            seg[4+cnt]=segment(M,M+Z);
            SI(seg,4+cnt,res,m);
        }
        else{
            point M=point((now.x+x)/2,(now.y+y)/2);
            point D=point(x,y)-now;
            point Z=point(D.y,-D.x);
            ++cnt;
            seg[4+cnt]=segment(M,M+Z);
            SI(seg,4+cnt,res,m);
        }
        printf("%.2f\n",poly_area(res,m)+eps);
        now=point(x,y);
    }
    return 0;
}
