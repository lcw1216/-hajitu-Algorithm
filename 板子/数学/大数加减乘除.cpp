#include<bits/stdc++.h>
using namespace std;
//字符串大数加减乘除
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
    // 如果 a < b，交换并标记负号
    if (a<b) {
        swap(a, b);
        neg = true;
    }
    int i = a.size() - 1, j = b.size() - 1;
    int borrow = 0;
    string ans = "";
    while (i >= 0 || j >= 0) {
        int diff = borrow;
        if (i >= 0) diff += (a[i--] - '0');
        if (j >= 0) diff -= (b[j--] - '0');
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        ans.push_back(diff + '0');
    }
    // 去除前导零，但保留一个 "0"
    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    if (neg) ans.push_back('-');
    reverse(ans.begin(), ans.end());
    return ans;
}

string str_mul(string a, string b) {
    if (a == "0" || b == "0") return "0";
    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0);
    // 从个位开始逐位相乘
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
        if (!(ans.empty() && num == 0)) // 跳过前导零
            ans.push_back(num + '0');
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
    while (carry) {
        ans.push_back((carry % 10) + '0');
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// ---------- 4. 大数除法（整数除法，返回商） ----------
string str_div(string a, string b) {
    if (b == "0") return "ERROR: Division by zero"; // 除数不能为0
    if (a<b) return "0";              // 被除数小于除数，商为0

    string rem = "";    // 当前余数
    string ans = "";    // 商

    for (char c : a) {
        // 余数后移一位，补上当前数字
        rem.push_back(c);
        // 去除余数的前导零（保持有效数字）
        size_t pos = rem.find_first_not_of('0');
        if (pos != string::npos) 
            rem = rem.substr(pos);
        else 
            rem = "0";

        // 试商：从 0~9 中找最大的 q，使得 b * q <= rem
        int q = 0;
        while (q < 9) {
            string tmp = str_mul_single(b, q + 1);
            if (tmp<=rem) 
                q++;
            else 
                break;
        }
        ans.push_back(q + '0');
        // 更新余数：rem = rem - b * q
        string sub_val = str_mul_single(b, q);
        rem = str_sub(rem, sub_val);  // 这里 rem 一定不小于 sub_val
    }

    // 去除商的前导零
    size_t pos = ans.find_first_not_of('0');
    if (pos != string::npos) 
        ans = ans.substr(pos);
    else 
        ans = "0";
    return ans;
}

int main(){
    string s1,s2;cin>>s1>>s2;
    string ans = str_sum(s1,s2);
    cout<<ans<<endl;
    return 0;
}