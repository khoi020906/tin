#include <bits/stdc++.h>

using namespace std;
int n,k,i,j,s,b[10000000],l,r; map<int,int>mp; pair<int,int>a[10000000];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
        a[i]={x,i};
    }
    sort(a+1,a+1+n);
    int cnt=0;
    for (auto it:a) b[cnt++]=it.first;
    for (i=1;i<=n-2;i++)
    {
        long long s=k-a[i].first;
        l=i+1;
        r=n;
        while (l<r)
        {
            long long sum=b[l]+b[r];
            if (sum==s) break;
            if (sum<s) l++;
            else if (sum>s) r--;
        }
        if (b[l]+b[r]==s && l!=r)
        {
            cout<<a[i].second<<" "<<a[l].second<<" "<<a[r].second<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
