class Solution {
public:

    bool fun(int index, int open, int close, string &s, vector<vector<vector<int>>> &dp) {
        if (index == s.size()) {
            if (open == close) return true;
            return false;
        }
        if (open < close) return false;
        if (dp[index][open][close] != -1) return dp[index][open][close];
        if (s[index] == ')') return fun(index + 1, open, close + 1, s, dp);
        if (s[index] == '(') return fun(index + 1, open + 1, close, s, dp);

        bool ans1 = 0, ans2 = 0, ans3 = 0;
        if (s[index] == '*') {
            ans1 = fun(index + 1, open + 1, close, s, dp);
            ans2 = fun(index + 1, open, close + 1, s, dp);
            ans3 = fun(index + 1, open, close, s, dp);
        }
        return dp[index][open][close] = (ans1 | ans2 | ans3);
    }

    bool checkValidString(string s) {
        vector<vector<vector<int>>> dp(100, vector<vector<int>> (100, vector<int> (100, -1)));
        return fun(0, 0, 0, s, dp);
    }
};