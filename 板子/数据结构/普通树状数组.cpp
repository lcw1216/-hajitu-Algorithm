#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
class BIT {
    vector<T> tree;
public:
    BIT(int n) : tree(n + 1) {}

    void update(int i, T val) {
        for (; i < tree.size(); i += i & -i) tree[i] += val;
    }

    T pre(int i) const {
        T res{};
        for (; i > 0; i &= i - 1) res += tree[i];
        return res;
    }
    
    T query(int l, int r) const {
        if (r < l) return 0;
        return pre(r) - pre(l - 1);
    }
};
    const int n = 100000;
    BIT<long long> bit(n);      // 下标 1..n
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i,v,l,r;
    cin>>i>>v>>l>>r;
    bit.update(i, v);           // 位置 i 增加 v（单点加）
    long long s = bit.pre(i);   // 前缀和 a[1]+...+a[i]
    long long t = bit.query(l, r);  // 区间和 a[l]+...+a[r]，l<=r
    return 0;
}