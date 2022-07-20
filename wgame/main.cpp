#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MOD=1e9+7;
int n,m; char a[3000][3000]; long long d[300][300][300],dp[300][300][300],k,i,j; string s;
long long f(int i, int j,int x,int y)
{
    ll res=0;
    if (a[i][j]!=a[x][y]) return 0;
    if (a[i][j]=='#' || a[x][y]=='#') return 0;
    if (i>x || j>y) return 0;
    if (d[i][j][x]) return dp[i][j][x];
    d[i][j][x]=1;
    if ((x-i)+(y-j)<=1)
    {
        return dp[i][j][x]= 1;
    }
    dp[i][j][x]+=f(i+1,j,x-1,y)%MOD;
    dp[i][j][x]+=f(i,j+1,x,y-1)%MOD;
    dp[i][j][x]+=f(i+1,j,x,y-1)%MOD;
    dp[i][j][x]+=f(i,j+1,x-1,y)%MOD;
    return dp[i][j][x]%MOD;
}
int main()
{
    cin>>n>>m>>k;
    cin>>s;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) cin>>a[i][j];
    cout<< f(1,1,n,m);
    return 0;
}
