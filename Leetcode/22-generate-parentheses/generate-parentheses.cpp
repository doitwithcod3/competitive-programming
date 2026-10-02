class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> ans;
        int size = 2 * n;

        for (int i = 0; i < (1 << size); ++i) {
            int zero = 0, one = 0;
            for (int j = 0; j < size; ++j) {
                if (i & (1 << j)) one++;
                else zero++;
                if (zero > one) break;
            }
            if (one == n) {
                string valid;
                for (int j = 0; j < size; ++j) {
                    if (i & (1 << j)) valid.push_back('(');
                    else valid.push_back(')');   
                }
                ans.insert(valid);
            }
        }
        return vector<string> (ans.begin(), ans.end());
    }
};