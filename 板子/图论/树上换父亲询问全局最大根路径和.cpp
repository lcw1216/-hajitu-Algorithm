#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;

ll rnk[N];
ll a[N], sum[N];
int p[N];
vector<int> e[N];

struct SegT {
    ll mx[N*4];
    ll tag[N*4];

    void up(int i) {
        mx[i] = max(mx[i*2], mx[i*2+1]);
    }

    void lazy(int i,ll v) {
        tag[i] += v;
        mx[i] += v;
    }
    void down(int i) {
        if (tag[i]) {
            lazy(i*2,tag[i]);
            lazy(i*2+1,tag[i]);
            tag[i] = 0;
        }
    }
    void build(int i,int l,int r) {
        if (l == r) {
            mx[i] = rnk[l];
        } else {
            int mid = (l + r) / 2;
            build(i*2,l,mid);
            build(i*2+1,mid+1,r);
            up(i);
        }
    }
    void add(int i,int l,int r,int jl,int jr,ll v) {
        if (jl <=l && r <= jr) {
            lazy(i,v);
        } else {
            int mid = (l + r) / 2;
            down(i);
            if (jl <= mid) add(i*2,l,mid,jl,jr,v);
            if (jr > mid) add(i*2+1,mid+1,r,jl,jr,v);
            up(i);
        }
    }
    ll query(int i,int l,int r,int jl,int jr) {
        if (jl <= l && r<= jr) {
            return mx[i];
        } else {
            ll res = -1e18;
            int mid = (l + r) / 2;
            down(i);
            if (jl <= mid) res = max(res, query(i*2,l,mid,jl,jr));
            if (jr > mid)res = max(res, query(i*2+1,mid+1,r,jl,jr));
            up(i);
            return res;
        }
    }
}T;

int n, dfncnt;
int L[N];
int R[N];

void dfs(int u) {
    L[u] = ++dfncnt;
    sum[u] += a[u];
    rnk[dfncnt] = sum[u];
    for (auto v: e[u]) {
        sum[v] = sum[u];
        dfs(v);
    }
    R[u] = dfncnt;
}

void solve() {
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        e[p[i]].push_back(i);
    }
    dfs(1);
    T.build(1,1,n);
    for (int i= 1; i <= q; i++) {
        int x, y;
        cin >> y >> x;
        int z = p[y];
        ll delta = sum[x]-sum[z];
        T.add(1,1,dfncnt,L[y],R[y],delta);
        cout << T.query(1,1,dfncnt,1,dfncnt) << "\n";
        T.add(1,1,dfncnt,L[y],R[y],-delta);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();    
}
// 64 位输出请用 printf("%lld")
