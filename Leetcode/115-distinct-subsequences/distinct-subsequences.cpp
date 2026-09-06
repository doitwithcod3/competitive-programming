class Solution {
public:
    const int mod = 1e9 + 7;
    // Iterative + Space Optimized
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> one(m + 1, 0);
        vector<int> two(m + 1, 0);
        one[0] = 1;

        for (int i = 1; i <= n; ++i) {
            two[0] = 1;
            for (int j = 1; j <= m; ++j) {
                two[j] = (one[j] + 0LL + (s[i - 1] == t[j - 1] ? one[j - 1] : 0)) % mod;
            }
            one = two;
        }
        return two[m];
    }
};