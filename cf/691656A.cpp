#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        n = n-m;
        int mx = m,mn;
        if(n-1>=m&&m!=0)mn = 1;
            else{
                mn = m/(n+1);
                if(m%(n+1)!=0)mn++;
            }
        cout<<mx<<' '<<mn<<endl;
    }
    return 0;
}