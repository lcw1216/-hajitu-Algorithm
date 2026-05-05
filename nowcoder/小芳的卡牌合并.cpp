#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        while(n%2==0)n/=2;
        if(n==1)cout<<"Fang"<<endl;
        else cout<<"Ben"<<endl;
    }
    return 0;
}