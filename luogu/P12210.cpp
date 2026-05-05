#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int b1,b2,b3,cnta,cntb,va,vb;
        cin>>b1>>b2>>b3>>cnta>>cntb>>va>>vb;
        int ans = INT_MIN;
        for(int i=0;i<=cnta&&i*va<=b1;i++){
            int lb1 = min(cntb,(b1-i*va)/vb);
            for(int j=0;i+j<=cnta&&j*va<=b2;j++){
                int lb2 = min(cntb-lb1,(b2-j*va)/vb);
                for(int k=0;i+j+k<=cnta&&k*va<=b3;k++){
                    int lb3 = min(cntb-lb1-lb2,(b3-k*va)/vb);
                    ans = max(ans,i+j+k+lb1+lb2+lb3);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}