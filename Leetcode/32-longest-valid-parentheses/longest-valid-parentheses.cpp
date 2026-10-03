class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> last;
        last.push(-1);
        for (int current = 0; current < s.size(); ++current) {
            if (s[current] == '(') {
                last.push(current);
            }
            else {
                last.pop();
                if (last.size() == 0) last.push(current);
                else ans = max(ans, current - last.top());
            }
        }
        return ans;
    }
};