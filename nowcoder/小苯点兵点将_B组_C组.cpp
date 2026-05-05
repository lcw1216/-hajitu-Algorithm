#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int l,r;cin>>l>>r;
        bool res = false;
        for(int i=l;i<=r;i++){if(i%3==0){res=true;break;}}
        if(res)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}