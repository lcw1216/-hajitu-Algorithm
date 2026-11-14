#include<bits/stdc++.h>
using namespace std;
// 如果两字符串相等，返回true

constexpr int M = 1e9 + 7;
constexpr int B = 233;

using ll = long long;

int get_hash(const string& s) {
  int res = 0;
  for (int i = 0; i < s.size(); ++i) {
    res = ((ll)res * B + s[i]) % M;
  }
  return res;
}

bool cmp(const string& s, const string& t) {
  return get_hash(s) == get_hash(t);
}
int main(){
    string s1,s2;cin>>s1>>s2;
    if(cmp(s1,s2))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}