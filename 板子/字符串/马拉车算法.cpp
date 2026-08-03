#include<bits/stdc++.h>
using namespace std;
//求最长回文子串On马拉车算法
int manacher(string s){
    string t;t.push_back('^');
    t.push_back('.');
    for(auto si:s){t.push_back(si);t.push_back('.');}
    t.push_back('$');
    int mid = -1,mr = 0;
    vector<int> p(t.size());
    for(int i=0;i<(int)t.size();i++){
        if(i<mr)p[i] = min(p[2*mid-i],mr-i);
        else p[i] = 1;
        while(p[t[i-p[i]]]==p[t[i+p[i]]])p[i]++;
        if(i+p[i]>mr){mid = i;mr = i+p[i];}
    }
    return *max_element(p.begin(),p.end())-1;
}
int main(){
    string s;cin>>s;
    int res = manacher(s);
    cout<<res<<endl;
    return 0;
}