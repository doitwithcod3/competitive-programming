class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> score;
        score.push_back(0);
        for (char ch : s) {
            if (ch == '(') score.push_back(0);
            else {
                auto last = score.back(); score.pop_back();
                score.back() += max(last * 2, 1);
            }
        }
        return score.back();
    }
};