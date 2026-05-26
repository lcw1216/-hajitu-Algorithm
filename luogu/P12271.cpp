#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int len = s.length();
    vector<vector<int>> ps(26,vector<int>(len+1,0));
    for(int i=0;i<26;i++){
        for(int j=0;j<len;j++) if(s[j]==(char)(i+'a'))ps[i][j]=1;
        for(int j=1;j<=len;j++) ps[i][j]+=ps[i][j-1];
    }
    vector<vector<int>> ct(26);
    stack<int> pos;
    for(int i=0;i<len;i++){
        if(s[i]=='(')pos.push(i);
        else if(s[i]==')'){
            int l = pos.top(),r = i;
            pos.pop();
            for(int j=0;j<26;j++)
                    ct[j].push_back(ps[j][r-1]-ps[j][l]);
        }
    }
    //逆向dp可实现o1查询
    vector<vector<int>> dp(26,vector<int>(len+2,0));
    for(int i=0;i<26;i++) for(int j=0;j<(int)ct[i].size();j++) dp[i][ct[i][j]]++;
    for(int i=0;i<26;i++) for(int j=len;j>=0;j--) dp[i][j]+=dp[i][j+1];
    int q;cin>>q;
    while(q--){
        char c;
        int x;
        cin>>c>>x;
        if(x>len){cout<<0<<endl;continue;}
        cout<<dp[(int)(c-'a')][x]<<endl;
    }
    return 0;
}