#include <bits/stdc++.h>

using namespace std;
const int N=1e6;
int n,i,p[N],cnt; vector<int>a;
void sang()
{
    for (int i=1;i<=N;i++)
    {
        for (int j=i;j<=N;j+=i) p[j]++;
    }
}
int main()
{
    cin>>n;
    sang();
    for (i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            a.push_back(i);
            if (i*i!=n) a.push_back(n/i);
        }
    }
    cnt=0;
    for (auto it:a)
    {
        if (it<=N)
        {
            if (it<=5) continue;
            if (p[it]==4) cnt++;
        }
        else
        {
            long long d=0;
            for (i=2;i*i<=it;i++)
            {
                if (it%i==0)
                {
                    d++;
                    if (i*i!=it) d++;
                    if (d>2) break;
                }

            }
            if (d==2) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
