#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int to_len(int x){
    int ans = 0;
    while(x!=0){
        x/=2;
        ans++;
    }
    return ans;
}
int main(){
    int T;cin>>T;
    while(T--){
        unordered_map<int,int> mp;
        int n,x,ans = 0;cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            mp[to_len(x)]++;
        }
        for(const auto&pair:mp) ans = max(ans,pair.second);
        cout<<ans<<endl;
    }
    return 0;
}
