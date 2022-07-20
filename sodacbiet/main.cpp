#include <bits/stdc++.h>
using namespace std;
const int N=3e6;
long long t,l,r,p[N],a[N],i,j;
int kt(long long n)
{
   long long s=0;
   while (n!=0)
   {
       s=s+n%10;
       n=n/10;
   }
   if (s%5==0) return 1;
   return 0;
}
void sang()
{
    p[0]=1;
    p[1]=1;
    for (i=2;i*i<=N;i++)
        if (!p[i])
    {
        for (j=i*i;j<=N;j+=i)
        {
            p[j]=1;
        }
    }
}
int main()
{
     cin >>t;
     sang();
     a[0]=0;
     for (int i=1;i<=N;i++)
     {
         if (p[i])
         {
             a[i]=a[i-1];
             continue;
         }
         if (kt(i))
         {
             a[i]=a[i-1]+1;
         }
         else a[i]=a[i-1];
     }
    while (t--)
    {
        cin >>l>>r;
        cout<<a[r]-a[l-1]<<"\n";
    }
    return 0;
}
