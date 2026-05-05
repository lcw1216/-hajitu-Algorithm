#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int len = s.length();
    string res;
    if(s[0]>'Z')s[0]-=('a'-'A');
    res.push_back(s[0]);
    for(int i=1;i<len;i++){
        if(s[i]<'a'&&s[i]!='.'&&res.back()!='.')res.push_back('.');
        if(res.back()=='.'&&s[i]>='a')s[i]-=('a'-'A');
        res.push_back(s[i]);
    }
    if(res.back()!='.')res.push_back('.');
    cout<<res<<endl;
    return 0;
}