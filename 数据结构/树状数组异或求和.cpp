#include <array>
#include <iostream>
#include <valarray>
#include <vector>
//异或线段数板子 输入1 l r 代表对l r区间求和 输入2 l r k代表区间内的所有数都异或于k
using namespace std;

using ll = long long;

const int WEI = 17;

struct Node {
    int tag = 0;
    array<int, WEI> cnt;
    Node() = default;
    Node(int a) {
        for (int i = 0; i < WEI; i++) {
            cnt[i] = (a >> i) & 1;
        }
    }
    void AddTag(int x, int l, int r) {
        int len = r - l + 1;
        for (int i = 0; i < WEI; i++) {
            if (x & (1 << i)) {
                cnt[i] = len - cnt[i];
            }
        }
        tag ^= x;
    }
    ll Sum() {
        ll res = 0;
        for (int i = 0; i < WEI; i++) {
            res += (ll)cnt[i] << i;
        }
        return res;
    }
    void Update(const Node& a, const Node& b) {
        for (int i = 0; i < WEI; i++) {
            cnt[i] = a.cnt[i] + b.cnt[i];
        }
    }
};

int n;
int m;

vector<int> a;
vector<Node> xds;

void Pushdown(int p, int l, int r) {
    if (xds[p].tag) {
        int mid = (l + r) >> 1;
        xds[p << 1].AddTag(xds[p].tag, l, mid);
        xds[p << 1 | 1].AddTag(xds[p].tag, mid + 1, r);
        xds[p].tag = 0;
    }
}

void Update(int p) {
    xds[p].Update(xds[p << 1], xds[p << 1 | 1]);
}

void Build(int p, int l, int r) {
    if (l == r) {
        xds[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(p << 1, l, mid);
    Build(p << 1 | 1, mid + 1, r);
    Update(p);
}

void Xor(int l, int r, int k, int p, int lp, int rp) {
    if (r < lp || rp < l) {
        return;
    }
    if (l <= lp && rp <= r) {
        xds[p].AddTag(k, lp, rp);
        return;
    }
    Pushdown(p, lp, rp);
    int mid = (lp + rp) >> 1;
    Xor(l, r, k, p << 1, lp, mid);
    Xor(l, r, k, p << 1 | 1, mid + 1, rp);
    Update(p);
}

ll Sum(int l, int r, int p, int lp, int rp) {
    if (r < lp || rp < l) {
        return 0;
    }
    if (l <= lp && rp <= r) {
        return xds[p].Sum();
    }
    Pushdown(p, lp, rp);
    int mid = (lp + rp) >> 1;
    return Sum(l, r, p << 1, lp, mid) + Sum(l, r, p << 1 | 1, mid + 1, rp);
}

void Solve() {
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    xds.resize(n * 4 + 1);
    Build(1, 1, n);
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        switch (op) {
            case 1:
                cout << Sum(l, r, 1, 1, n) << '\n';
                break;
            case 2:
                int k;
                cin >> k;
                Xor(l, r, k, 1, 1, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
}
