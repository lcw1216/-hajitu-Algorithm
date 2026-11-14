#include<bits/stdc++.h>
using namespace std;
//十进制转换二进制字符串
string to_b(int x){
    string ans;
    while(x>0){
        ans.push_back((char)(x%2+'0'));
        x/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
//二进制字符串转换十进制
int to_v(string s){
    if(s.empty()||s=="0")return 0;
    int tp = 1,ans = 0;
    for(int i=(int)s.length()-1;i>=0;i--){
        if(s[i]=='1')ans+=tp;
        tp*=2;
    }
    return ans;
}