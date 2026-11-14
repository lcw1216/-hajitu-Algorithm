#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool lt(const string&x,const string&y){
    if(x.size()!=y.size())return x.size()<y.size();
    return x<y;
}

string str_sum(string s1,string s2){
    int i = s1.length()-1;
    int j = s2.length()-1;
    int carry = 0;
    string ans;
    while(i>=0||j>=0||carry>0){
        int sum = carry;
        if(i>=0)sum+=(s1[i--]-'0');
        if(j>=0)sum+=(s2[j--]-'0');
        ans.push_back((sum%10)+'0');
        carry = sum/10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string str_sub(string a, string b) {
    bool neg = false;
    if (lt(a, b)) { swap(a, b); neg = true; }
    int i = a.size() - 1, j = b.size() - 1;
    int borrow = 0;
    string ans = "";
    while (i >= 0 || j >= 0) {
        int diff = -borrow;
        if (i >= 0) diff += (a[i--] - '0');
        if (j >= 0) diff -= (b[j--] - '0');
        if (diff < 0) { diff += 10; borrow = 1; } else { borrow = 0; }
        ans.push_back(diff + '0');
    }
    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    if (neg) ans.push_back('-');
    reverse(ans.begin(), ans.end());
    return ans;
}

string str_mul(string a, string b) {
    if (a == "0" || b == "0") return "0";
    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }
    string ans = "";
    for (int num : res) {
        if (!(ans.empty() && num == 0)) ans.push_back(num + '0');
    }
    return ans.empty() ? "0" : ans;
}

string str_mul_single(string a, int b) {
    if (a == "0" || b == 0) return "0";
    int carry = 0;
    string ans = "";
    for (int i = a.size() - 1; i >= 0; --i) {
        int prod = (a[i] - '0') * b + carry;
        ans.push_back((prod % 10) + '0');
        carry = prod / 10;
    }
    while (carry) { ans.push_back((carry % 10) + '0'); carry /= 10; }
    reverse(ans.begin(), ans.end());
    return ans;
}

string str_div(string a, string b) {
    if (b == "0") return "ERROR";
    if (lt(a, b)) return "0";
    string rem = "";
    string ans = "";
    for (char c : a) {
        rem.push_back(c);
        size_t pos = rem.find_first_not_of('0');
        if (pos != string::npos) rem = rem.substr(pos); else rem = "0";
        int q = 0;
        while (q < 9) {
            string tmp = str_mul_single(b, q + 1);
            if (!lt(rem, tmp)) q++; else break;
        }
        ans.push_back(q + '0');
        string sub_val = str_mul_single(b, q);
        rem = str_sub(rem, sub_val);
    }
    size_t pos = ans.find_first_not_of('0');
    if (pos != string::npos) ans = ans.substr(pos); else ans = "0";
    return ans;
}

void solve(){
    string a,b;cin>>a>>b;
    cout<<str_sum(a,b)<<" "<<str_sub(a,b)<<" "<<str_mul(a,b)<<" "<<str_div(a,b)<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}