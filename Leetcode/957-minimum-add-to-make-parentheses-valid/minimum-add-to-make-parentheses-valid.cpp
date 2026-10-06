class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0, ans = 0;
        for (char ch : s) {
            if (ch == '(') ++open;
            else ++close;

            if (close > open) {
                ans++;
                open++;
            }
        }
        ans += abs(open - close);
        return ans;
    }
};