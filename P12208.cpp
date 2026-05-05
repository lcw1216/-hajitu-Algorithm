#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    string s;cin>>s;
    int len = s.length();
    unordered_map<char,int> mp;
    for(int i=0;i<len;i++)mp[s[i]]++;
    bool res = true;
    for(const auto &pair: mp) if(pair.second%2!=0)res = false;
    if(res)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
  
}