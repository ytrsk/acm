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
int dp[17][17];
int main(){
    dp[1][1]=0;
    dp[1][2]=1;
    dp[1][3]=0;
    dp[1][4]=0;
    dp[1][5]=0;
    dp[1][6]=0;
    dp[1][7]=0;
    dp[1][8]=0;
    dp[1][9]=0;
    dp[1][10]=0;
    dp[1][11]=0;
    dp[1][12]=0;
    dp[1][13]=0;
    dp[1][14]=0;
    dp[1][15]=0;
    dp[1][16]=0;
    dp[2][1]=1;
    dp[2][2]=0;
    dp[2][3]=0;
    dp[2][4]=0;
    dp[2][5]=0;
    dp[2][6]=0;
    dp[2][7]=0;
    dp[2][8]=0;
    dp[2][9]=0;
    dp[2][10]=0;
    dp[2][11]=0;
    dp[2][12]=0;
    dp[2][13]=0;
    dp[2][14]=0;
    dp[2][15]=0;
    dp[2][16]=0;
    dp[3][1]=0;
    dp[3][2]=0;
    dp[3][3]=0;
    dp[3][4]=0;
    dp[3][5]=0;
    dp[3][6]=0;
    dp[3][7]=0;
    dp[3][8]=0;
    dp[3][9]=0;
    dp[3][10]=0;
    dp[3][11]=0;
    dp[3][12]=0;
    dp[3][13]=0;
    dp[3][14]=0;
    dp[3][15]=0;
    dp[3][16]=0;
    dp[4][1]=0;
    dp[4][2]=0;
    dp[4][3]=0;
    dp[4][4]=0;
    dp[4][5]=0;
    dp[4][6]=0;
    dp[4][7]=0;
    dp[4][8]=0;
    dp[4][9]=0;
    dp[4][10]=0;
    dp[4][11]=0;
    dp[4][12]=0;
    dp[4][13]=0;
    dp[4][14]=0;
    dp[4][15]=0;
    dp[4][16]=0;
    dp[5][1]=0;
    dp[5][2]=0;
    dp[5][3]=0;
    dp[5][4]=0;
    dp[5][5]=0;
    dp[5][6]=6;
    dp[5][7]=0;
    dp[5][8]=108;
    dp[5][9]=0;
    dp[5][10]=1182;
    dp[5][11]=0;
    dp[5][12]=10338;
    dp[5][13]=0;
    dp[5][14]=79818;
    dp[5][15]=0;
    dp[5][16]=570342;
    dp[6][1]=0;
    dp[6][2]=0;
    dp[6][3]=0;
    dp[6][4]=0;
    dp[6][5]=6;
    dp[6][6]=0;
    dp[6][7]=124;
    dp[6][8]=62;
    dp[6][9]=1646;
    dp[6][10]=1630;
    dp[6][11]=18120;
    dp[6][12]=25654;
    dp[6][13]=180288;
    dp[6][14]=317338;
    dp[6][15]=1684956;
    dp[6][16]=3416994;
    dp[7][1]=0;
    dp[7][2]=0;
    dp[7][3]=0;
    dp[7][4]=0;
    dp[7][5]=0;
    dp[7][6]=124;
    dp[7][7]=0;
    dp[7][8]=13514;
    dp[7][9]=0;
    dp[7][10]=765182;
    dp[7][11]=0;
    dp[7][12]=32046702;
    dp[7][13]=0;
    dp[7][14]=136189727;
    dp[7][15]=0;
    dp[7][16]=378354090;
    dp[8][1]=0;
    dp[8][2]=0;
    dp[8][3]=0;
    dp[8][4]=0;
    dp[8][5]=108;
    dp[8][6]=62;
    dp[8][7]=13514;
    dp[8][8]=25506;
    dp[8][9]=991186;
    dp[8][10]=3103578;
    dp[8][11]=57718190;
    dp[8][12]=238225406;
    dp[8][13]=965022920;
    dp[8][14]=388537910;
    dp[8][15]=937145938;
    dp[8][16]=315565230;
    dp[9][1]=0;
    dp[9][2]=0;
    dp[9][3]=0;
    dp[9][4]=0;
    dp[9][5]=0;
    dp[9][6]=1646;
    dp[9][7]=0;
    dp[9][8]=991186;
    dp[9][9]=0;
    dp[9][10]=262834138;
    dp[9][11]=0;
    dp[9][12]=462717719;
    dp[9][13]=0;
    dp[9][14]=560132342;
    dp[9][15]=0;
    dp[9][16]=699538539;
    dp[10][1]=0;
    dp[10][2]=0;
    dp[10][3]=0;
    dp[10][4]=0;
    dp[10][5]=1182;
    dp[10][6]=1630;
    dp[10][7]=765182;
    dp[10][8]=3103578;
    dp[10][9]=262834138;
    dp[10][10]=759280991;
    dp[10][11]=264577134;
    dp[10][12]=712492587;
    dp[10][13]=886997066;
    dp[10][14]=577689269;
    dp[10][15]=510014880;
    dp[10][16]=807555438;
    dp[11][1]=0;
    dp[11][2]=0;
    dp[11][3]=0;
    dp[11][4]=0;
    dp[11][5]=0;
    dp[11][6]=18120;
    dp[11][7]=0;
    dp[11][8]=57718190;
    dp[11][9]=0;
    dp[11][10]=264577134;
    dp[11][11]=0;
    dp[11][12]=759141342;
    dp[11][13]=0;
    dp[11][14]=567660301;
    dp[11][15]=0;
    dp[11][16]=47051173;
    dp[12][1]=0;
    dp[12][2]=0;
    dp[12][3]=0;
    dp[12][4]=0;
    dp[12][5]=10338;
    dp[12][6]=25654;
    dp[12][7]=32046702;
    dp[12][8]=238225406;
    dp[12][9]=462717719;
    dp[12][10]=712492587;
    dp[12][11]=759141342;
    dp[12][12]=398579168;
    dp[12][13]=83006813;
    dp[12][14]=821419653;
    dp[12][15]=942235780;
    dp[12][16]=558077885;
    dp[13][1]=0;
    dp[13][2]=0;
    dp[13][3]=0;
    dp[13][4]=0;
    dp[13][5]=0;
    dp[13][6]=180288;
    dp[13][7]=0;
    dp[13][8]=965022920;
    dp[13][9]=0;
    dp[13][10]=886997066;
    dp[13][11]=0;
    dp[13][12]=83006813;
    dp[13][13]=0;
    dp[13][14]=690415372;
    dp[13][15]=0;
    dp[13][16]=620388364;
    dp[14][1]=0;
    dp[14][2]=0;
    dp[14][3]=0;
    dp[14][4]=0;
    dp[14][5]=79818;
    dp[14][6]=317338;
    dp[14][7]=136189727;
    dp[14][8]=388537910;
    dp[14][9]=560132342;
    dp[14][10]=577689269;
    dp[14][11]=567660301;
    dp[14][12]=821419653;
    dp[14][13]=690415372;
    dp[14][14]=796514774;
    dp[14][15]=696587391;
    dp[14][16]=175421667;
    dp[15][1]=0;
    dp[15][2]=0;
    dp[15][3]=0;
    dp[15][4]=0;
    dp[15][5]=0;
    dp[15][6]=1684956;
    dp[15][7]=0;
    dp[15][8]=937145938;
    dp[15][9]=0;
    dp[15][10]=510014880;
    dp[15][11]=0;
    dp[15][12]=942235780;
    dp[15][13]=0;
    dp[15][14]=696587391;
    dp[15][15]=0;
    dp[15][16]=856463275;
    dp[16][1]=0;
    dp[16][2]=0;
    dp[16][3]=0;
    dp[16][4]=0;
    dp[16][5]=570342;
    dp[16][6]=3416994;
    dp[16][7]=378354090;
    dp[16][8]=315565230;
    dp[16][9]=699538539;
    dp[16][10]=807555438;
    dp[16][11]=47051173;
    dp[16][12]=558077885;
    dp[16][13]=620388364;
    dp[16][14]=175421667;
    dp[16][15]=856463275;
    dp[16][16]=341279366;
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        printf("%d\n",dp[n][m]);
    }
    return 0;
}