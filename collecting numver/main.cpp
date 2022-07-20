#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;

int N, x, cnt, pos[maxN];

int main(){
    cin>>N;
    for(int i = 1; i <= N; i++){
        cin>>x;
        pos[x] = i;
    }

    cnt = 1;
    for(int i = 2; i <= N; i++)
        if(pos[i-1] > pos[i])
            cnt++;
    cout<<cnt;
}
