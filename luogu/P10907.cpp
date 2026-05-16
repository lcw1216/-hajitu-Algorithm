#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0)return a;
    while(b){
        int t = b;
        b = a%b;
        a = t;
    }
    return a;
}
int main(){
    int n;cin>>n;
    map<pair<int,int>,int>mp;
    int ans = 0;
    for(int i=0;i<n;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        int l=c-a,r=d-b;
        int ys;
        ys = gcd(abs(l),abs(r));
        l = l/ys,r = r/ys;
        for(int x=a,y=b;;x+=l,y+=r){
                mp[{x,y}]++;
                if(x==c&&y==d)break;
            }
        }
    for(const auto& it:mp) if(it.second>=2)ans++;
    cout<<ans<<endl;
    return 0;
}