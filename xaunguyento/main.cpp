#include <bits/stdc++.h>

using namespace std;
map<char,int>mp; int k; vector<char>a;
int kt(long long k)
{
    if (k<2) return 0;
    for (int i=2;i*i<=k;i++)
        if (k%i==0) return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        string s; mp.clear(); k=0;
        cin>>s;
        for (auto x:s)
        {
            mp[x]++;
        }
        for (auto it:mp) if (it.second==1) k++;
        if (kt(k)) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
    return 0;
}
