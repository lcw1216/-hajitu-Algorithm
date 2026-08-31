#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int strto_num(string s){
        int pos = -1,len = s.length();
        for(int i=0;i<len;i++)if(s[i]!='0'){pos = i;break;}
        if(pos==-1)return 0;
        int ans = 0;
        for(int i=pos;i<len;i++){
            int t = (int)(s[i]-'0');
            ans = ans*10+t;
        }
        return ans;
    }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}