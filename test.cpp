#include<bits/stdc++.h>
using namespace std;
bool check(int x,int L,int R){
    for(int i=1;i*i<=x;i++){
        if(x%i==0&&(i>=L&&i<=R||x/i>=L&&x/i<=R))
        return false;
    }
    return true;
}
int sv(int n,int L,int R){
    for(int x=0;;x++){
        if(check(n+x,L,R)||check(n-x,L,R))
        return x;
    }
    return 0;
}
int main(){
    int n,L,R;
    cin>>n>>L>>R;
    int ans = sv(n,L,R);
    cout<<ans;
    return 0;
}