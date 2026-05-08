#include<bits/stdc++.h>
using namespace std;
int to_sum(int n){
    string s = to_string(n);
    int ans = 0,len = s.length();
    for(int i=0;i<len;i++){
        ans += (int)(s[i]-'0');
    }
    return ans;
}
int main(){
    int n;cin>>n;
    int ans = 0;
    while(n>0){
        int tmp = to_sum(n);
        n = n - tmp;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}