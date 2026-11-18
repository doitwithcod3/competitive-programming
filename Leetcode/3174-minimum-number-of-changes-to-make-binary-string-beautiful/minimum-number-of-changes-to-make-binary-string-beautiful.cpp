class Solution {
public:
    int minChanges(string s) {
        s.push_back('-');
        vector<int> construction;
        int count = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] != s[i]) {
                construction.push_back(count);
                count = 1;
            }
            else ++count;
        }
        int ans = 0, carry = 0;
        for (int i = 0; i < construction.size(); ++i) {
            if ((construction[i] + carry) % 2 == 1) { ans++; carry = 1; }
            else carry = 0;
        }
        return ans;
    }
};