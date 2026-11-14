#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> kmp(string s1,string s2){
    vector<int> kmps;
    int len2 = s2.size();
    kmps.resize(len2);
    int j = 0;
    for(int i=1;i<len2;i++){
        while(j&&s2[i]!=s2[j]) j = kmps[j-1];
        if(s2[i] == s2[j])j++;
        kmps[i] = j;
    }
    j = 0;
    vector<int> ans;
    for(int i=0;i<(int)s1.size();i++){
        while(j&&s1[i]!=s2[j])j = kmps[j-1];
        if(s1[i]==s2[j]){
            j++;
            if(j==len2){
                ans.push_back(i+2-len2);
                j = kmps[j-1];
            }
        }
    }
    return ans;
}
void solve(){
    string s1,s2;cin>>s1>>s2;
    vector<int> ans = kmp(s1,s2);
    for(int i=0;i<(int)ans.size();i++)cout<<ans[i]<<' ';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}