#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(),m = t.length();
        if(n<m)return 0;
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][m] = 1; 
        for(int i=n-1;i>=0;i--){
            char a = s[i];
            for(int j=m-1;j>=0;j--){
                char b = t[j];
                if(a == b)dp[i][j] = dp[i+1][j]+dp[i+1][j+1];
                else dp[i][j] = dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};