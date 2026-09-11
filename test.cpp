#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 200010;
int get(char c)
{
    if (isalpha(c)) return c - 'a';
    else return 26 + c - '0';
}
int n, ch[N][40], tot = 1, cnt[N];
void insert(string s)
{
    int m = s.length();
    s = " " + s;
    int u = 1;
    for (int j = 1; j <= m; ++j) {
        int c = get(s[j]);
        // 如果这个节点的子节点中没有这个字符，添加上并将该字符的节点号记录为++tot
        if (!ch[u][c])
        {
            ch[u][c] = ++tot;
        }
        cnt[u]++;
        u = ch[u][c];  // 往更深一层搜索
    }
    cnt[u]++;
}
void solve(){
    cin >> n;
    map<string, int>mp;
    for (int i = 1, op; i <= n; ++i) {
        cin >> op;
        if (op == 1)
        {
            string s;
            cin >> s;
            if (!mp.count(s))
            {
                insert(s);
            }
            mp[s]++;
            cout << mp[s] << '\n';
        }
        else if (op == 2)
        {
            string s;
            cin >> s;
            int m = s.length();
            s = " " + s;
            int u = 1;
            bool ok = true;
            for (int j = 1; j <= m; ++j) {
                int c = get(s[j]);
                if (!ch[u][c] || cnt[u] == 0)
                {
                    ok = false;
                    break;
                }
                u = ch[u][c];
            }
            cout << (cnt[u] > 0 && ok ? "YES\n" : "NO\n");
        }
        else
        {
            string s;
            cin >> s;
            int m = s.length();
            int u = 1;
            for (int j = 0; j < m; ++j) {
                int c = get(s[j]);
                cnt[u]--;
                u = ch[u][c];
            }
            cnt[u] = 0;
            mp.erase(s);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}