#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//N个点 N-1条边 q次询问查找两个点之间的最短路长度
int n;
vector<vector<int>> graph;
int _u;
int _v;
int q;

vector<int> h;

vector<vector<int>> st = {{}};
vector<int> pos;

int Min(int x, int y) {
    if (h[x] < h[y]) {
        return x;
    }
    return y;
}

void Dfs(int x, int fa) {
    pos[x] = st[0].size();
    st[0].push_back(x);
    for (const auto& y : graph[x]) {
        if (y != fa) {
            h[y] = h[x] + 1;
            Dfs(y, x);
            st[0].push_back(x);
        }
    }
}

void InitST() {
    st.resize(__lg(st[0].size()) + 1);
    for (int i = 1; i < st.size(); i++) {
        st[i].resize(st[0].size() - (1 << i) + 1);
        for (int j = 0; j < st[i].size(); j++) {
            st[i][j] = Min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int Mini(int l, int r) {
    if (l > r) {
        swap(l, r);
    }
    int t = __lg(r - l + 1);
    return Min(st[t][l], st[t][r - (1 << t) + 1]);
}

int Lca(int a, int b) {
    return Mini(pos[a], pos[b]);
}

int Dis(int a, int b) {
    return h[a] + h[b] - h[Lca(a, b)] * 2;
}

void Solve() {
    cin >> n;
    graph.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin >> _u >> _v >> q;
    h.resize(n + 1);
    pos.resize(n + 1);
    Dfs(1, 0);
    InitST();
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << min({Dis(x, y), Dis(x, _u) + Dis(_v, y), Dis(x, _v) + Dis(_u, y)}) <<
             '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
}
// 64 位输出请用 printf("%lld")
