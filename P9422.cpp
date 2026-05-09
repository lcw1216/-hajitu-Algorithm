#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    int ap=0,bp=0,la=0,lb=0,ta=a[0],tb=b[0];
    int ans = 0;
    while(ap<n||bp<n){
        if(ta<tb){ap++;ta+=a[ap];}
        else if(ta>tb){bp++;tb+=b[bp];}
        else {
            ans += ((ap-la)+(bp-lb));
            ap++; bp++;
            ta = a[ap]; tb = b[bp];
            la = ap; lb = bp;
        }
    }
    cout<<ans<<endl;
    return 0;
}