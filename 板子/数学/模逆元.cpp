#include <iostream>
using namespace std;

// 求 a 在模 m 下的逆元，要求 gcd(a, m) == 1
// 若不存在逆元，返回 -1
int mod_inv(int a, int m) {
    int m0 = m, y = 0, x = 1;
    if (m == 1) return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return (a == 1) ? x : -1;
}

int main() {
    int a;cin>>a;
    int mod = 1e9 + 7;
    int inv = mod_inv(a, mod);
    if (inv != -1)
        cout << inv << endl;                    // 333333336
    else
        cout << "No inverse" << endl;

    // 验证：必须用 long long 防止乘法溢出
    cout << (1LL * a * inv) % mod << endl;     // 1
    return 0;
}