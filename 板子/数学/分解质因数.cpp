#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;  
vector<int> p;       
bool vis[MAXN];  

void sieve(int n = MAXN - 1) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) p.push_back(i);
        for (int x : p) {
            if (1LL * i * x > n) break;
            vis[i * x] = true;
            if (i % x == 0) break;
        }
    }
}
vector<pair<ll, int>> ft(ll n) {
    vector<pair<ll, int>> res;
    for (int x : p) {
        if (1LL * x * x > n) break;  
        if (n % x == 0) {
            int cnt = 0;
            while (n % x == 0) n /= x, ++cnt;
            res.emplace_back(p, cnt);
        }
    }
    if (n > 1) res.emplace_back(n, 1); 
    return res;
}
int main(){

}