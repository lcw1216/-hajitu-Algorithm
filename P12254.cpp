#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    while(b){
        int t = b;
        b = a%b;
        a = t;
    }
    return a;
}
int main(){
    int K,T,n;cin>>K>>T;
    vector<int> cl(1e6+1,0);
    int dy = 1,ps = K+1,l = 1;
    for(int i=1;i<=1e6+1;i++){
        cl[i]=dy;
        if(ps>0)ps--;
        if(ps==0&&gcd(i,l)==1){
            l = i+1;
            ps = K+1;
            dy++;
        }
    }
    // for(int i=0;i<100;i++)cout<<i<<' '<<cl[i]<<endl;
    
    while(T--){
        cin>>n;
        cout<<cl[n]<<endl;
    }
    return 0;
}