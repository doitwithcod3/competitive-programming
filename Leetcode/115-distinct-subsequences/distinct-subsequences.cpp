class Solution {
public:
    const int mod = 1e9 + 7;
    // Iterative
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        // there is one way to get match when target = ""
        // irrespective of the length of the subsequence. I wont take any char, so count = 1
        for (int i = 0; i <= n; ++i) dp[i][0] = 1; 
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = (dp[i - 1][j] + 0LL + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0)) % mod;
            }
        }
        return dp[n][m];
    }
};