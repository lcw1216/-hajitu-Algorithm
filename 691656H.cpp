#include<bits/stdc++.h>
using namespace std;
//dp
int main(){
    int T;cin>>T;
    while(T--){
        string s;cin>>s;
        int fg = -1,t = 1;
        int len = s.length();
        vector<int> dp(len);
        for(int i=0;i<len;i++){
            if(fg==1&&s[i]=='1'){fg*=-1;dp[i]=1;}
            else if(fg==-1&&s[i]=='0'){fg*=-1;dp[i]=1;}
            else {dp[i]=2;fg*=-1;}
        }
        cout<<t<<endl;
    }
    return 0;
}