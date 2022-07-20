#include <bits/stdc++.h>

using namespace std;
long long n,i,a[35],vis[32][900000],dp[32][900000],k,s,sum,tmp;
long long f(int i, int sum)
{
    if (sum>k) return 0;
    if (sum==k) return 1;
    if (vis[i][sum]) return dp[i][sum];
    vis[i][sum]=1;
    long long res=0;
    for (int j=i+1;j<=n;j++)
        res+=f(j,sum+a[j]);
    return dp[i][sum]=res;
}
long long F(int i, long long sum)
{
    //if (i>n) return sum;
    if (sum>k) return sum-a[i];
    if (sum==k) return sum;
    if (vis[i][sum]) return dp[i][sum];
    vis[i][sum]=1;
    long long res=0;
    for (int j=i+1;j<=n;j++)
    res=max(res,F(j,sum+a[j]));
    return dp[i][sum]=res;

}
int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    k=s/2;
    tmp=F(0,0);
    //if (s%2==0) cout<<k-tmp<<" "; else cout<<k+1-tmp<<" ";
    cout<<s-2*tmp<<" ";
    memset(vis,0,sizeof vis);
    memset(dp,0,sizeof dp);
    k=tmp;
    if (s-2*tmp==0) cout<<f(0,0)/2;
    else cout<<f(0,0);
    return 0;
}
