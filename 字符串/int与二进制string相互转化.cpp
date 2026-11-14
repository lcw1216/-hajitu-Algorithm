#include<bits/stdc++.h>
using namespace std;
//贪心构造
string int_to_bit(int n){
    if(n==0)return "0";
    string s;
    while(n>0){
        s.push_back((char)(n%2+'0'));
        n/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
int bit_to_int(string s){
    int len = s.length(),pos = -1;
    for(int i=0;i<len;i++){
        if(s[i]=='1'){pos = i;break;}
    }
    if(pos==-1||len==0)return 0;
    else if(pos==len- 1)return 1;
    int ans = 1;
    for(int i=pos+1;i<len;i++){
        ans*=2;
        if(s[i]=='1')ans++;
    }
    return ans;
}
int main(){
    int n;cin>>n;
    
    return 0;
}