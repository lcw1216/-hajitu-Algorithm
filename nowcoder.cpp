#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
	cin >> n;
	vector<vector<int> >ans(n + 1);
	vector<int>cnt(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cnt[i] = i;
	}
	int c = 0, tot = n * (n + 1) / 2;
	int i = 1, j = n;
	while (c <= tot)
	{
		if (cnt[j])
		{
			ans[i].push_back(j);
			cnt[j]--;
			c++;
			i++;
			if (i > n) i = 1;
		}
		else j--;
	}
	for (int k = 1; k <= n; k++)
	{
		int sz = ans[k].size();
		for (int j = 0; j < sz; j++)
		{
			cout << ans[k][j] << " ";
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--)
    {
		solve();
	}
	return 0;
}