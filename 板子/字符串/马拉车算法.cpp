#include<bits/stdc++.h>
using namespace std;
//求最长回文子串O(n)马拉车算法
string preprocess(const string &s){
    string t = "^.";
    for(auto c : s){
        t.push_back(c);
        t.push_back('.');
    }
    t.push_back('$');
    return t;
}
vector<int> manacher(const string &s){
    string t = preprocess(s);
    int n = t.size();
    int mid = -1, mr = 0;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        if(i < mr) p[i] = min(p[2 * mid - i], mr - i);
        else p[i] = 1;
        while(t[i - p[i]] == t[i + p[i]]) p[i]++;
        if(i + p[i] > mr){
            mid = i;
            mr = i + p[i];
        }
    }
    return p;
}
//最长回文子串长度
int longestPalindrome(const string &s){
    vector<int> p = manacher(s);
    return *max_element(p.begin(), p.end()) - 1;
}
void solve(){
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
