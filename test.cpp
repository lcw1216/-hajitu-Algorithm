#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int N,Q;cin>>N;
    vector<ll> a(N);
    for(int i=0;i<N;i++)cin>>a[i];
    sort(a.begin(),a.end());
    cin>>Q;
    while(Q--){
        ll x;cin>>x;
        auto it = lower_bound(a.begin(),a.end(),x);
        int pos = it - a.begin();
        ll minval = INT_MAX;
        minval = min(minval,(ll)abs(x-a[pos]));
        if(pos>0)minval = min(minval,(ll)abs(x-a[pos-1]));
        // cout<<pos<<endl;
        cout<<minval<<endl;
    }
    return 0;
}