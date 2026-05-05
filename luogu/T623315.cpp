#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int n,x;cin>>n>>x;
        vector<int> h(n);
        for(int i=0;i<n;i++)cin>>h[i];
        bool res = true;
        for(int i=0;i<n-1;i++){
            int val = h[i+1]-h[i];
            if(val>1||val<-x){res=false;break;}
        }
        if(res)cout<<"Win"<<endl;
        else cout<<"Lose"<<endl;
    }
    return 0;
}