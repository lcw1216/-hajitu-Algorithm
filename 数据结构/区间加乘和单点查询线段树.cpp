#include <iostream>
#include <vector>
using namespace std;
//线段树
//区间加乘和单点求值，然后对值进行998244353取模
//op = 1区间加数 op = 2 区间乘数 op = 3 单点查询
using ll = long long;

const int MOD = 998244353;

int n;
int q;
vector<int> a;

struct Node {
    int mul = 1;
    int add = 0;
    void Mul(ll x) {
        mul = (ll)mul * x % MOD;
        add = (ll)add * x % MOD;
    }
    void Add(ll x) {
        add = (add + x) % MOD;
    }
    ll Op(ll x) {
        return (x * mul + add) % MOD;
    }
    void AddTag(const Node& other) {
        mul = (ll)mul * other.mul % MOD;
        add = ((ll)add * other.mul + other.add) % MOD;
    }
};

vector<Node> xds;

void Pushdown(int p) {
    xds[p << 1].AddTag(xds[p]);
    xds[p << 1 | 1].AddTag(xds[p]);
    xds[p] = {};
}

void Add(int l, int r, ll v, int p, int lp, int rp) {
    if (r < lp || rp < l) {return;}
    if (l <= lp && rp <= r) {
        xds[p].Add(v);
        return;
    }
    int mid = (lp + rp) >> 1;
    Pushdown(p);
    Add(l, r, v, p << 1, lp, mid);
    Add(l, r, v, p << 1 | 1, mid + 1, rp);
}

void Mul(int l, int r, ll v, int p, int lp, int rp) {
    if (r < lp || rp < l) {return;}
    if (l <= lp && rp <= r) {
        xds[p].Mul(v);
        return;
    }
    int mid = (lp + rp) >> 1;
    Pushdown(p);
    Mul(l, r, v, p << 1, lp, mid);
    Mul(l, r, v, p << 1 | 1, mid + 1, rp);
}

ll Val(ll x, int p, int l, int r) {
    if (l == r) {
        return xds[p].Op(a[x]);
    }
    int mid = (l + r) >> 1;
    Pushdown(p);
    if (x <= mid) {
        return Val(x, p << 1, l, mid);
    }
    return Val(x, p << 1 | 1, mid + 1, r);
}

void Solve() {
    cin >> n >> q;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    xds.assign(n * 4 + 1, {});
    while (q--) {
        int op;
        cin >> op;
        int l, r;
        ll x;
        switch (op) {
            case 1:
                cin >> l >> r >> x;
                Add(l, r, x, 1, 1, n);
                break;
            case 2:
                cin >> l >> r >> x;
                Mul(l, r, x, 1, 1, n);
                break;
            default:
                cin >> x;
                x = Val(x, 1, 1, n);
                if (x < 0) {
                    x += MOD;
                }
                cout << x << '\n';
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
}
