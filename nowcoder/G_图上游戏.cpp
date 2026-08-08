#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<char> special(n, 0);
    for(int i = 0; i < k; i++){
        int a; cin >> a; --a;
        special[a] = 1;
    }
    // cnt[v] = number of neighbors of v that are special or "strong" (in R1).
    // A non-special vertex becomes strong once cnt[v] >= 2, then it boosts its neighbors.
    vector<int> cnt(n, 0);
    vector<char> strong(n, 0);
    queue<int> q;
    for(int s = 0; s < n; s++){
        if(!special[s]) continue;
        for(int w : adj[s]) cnt[w]++;
    }
    for(int v = 0; v < n; v++){
        if(!special[v] && cnt[v] >= 2){
            strong[v] = 1;
            q.push(v);
        }
    }
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int w : adj[v]){
            cnt[w]++;
            if(!special[w] && !strong[w] && cnt[w] >= 2){
                strong[w] = 1;
                q.push(w);
            }
        }
    }
    // Winning starts: non-special vertices with at least one special/strong neighbor.
    vector<int> ans;
    for(int u = 0; u < n; u++){
        if(!special[u] && cnt[u] >= 1) ans.push_back(u + 1);
    }
    cout << ans.size() << "\n";
    for(size_t i = 0; i < ans.size(); i++){
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
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