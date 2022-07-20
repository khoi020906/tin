#include <iostream>

using namespace std;
long long t,i,n;
long long solve (long long n)
{
    if (n<=1) return 0;
    n=3*n*n-3*n+1;
    for (i=2;i*i<=n;i++)
    {
        if (n%i==0) return 0;
    }
    return 1;
}
int main()
{
    cin>>t;
    while (t--)
    {
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
