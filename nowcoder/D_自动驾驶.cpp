#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    unordered_map<string,int>mp;
    string dq;
    for(int i=0;i<k;i++)dq.push_back(s[i]);
    mp[dq]++;
    for(int i=k;i<n;i++){
        dq.erase(0,1);
        dq.push_back(s[i]);
        mp[dq]++;
    }
    int ct = 0;
    for(const auto&pair:mp){
        if(pair.second>1)ct++;
    }
    cout<<ct<<endl;
    return 0;
}