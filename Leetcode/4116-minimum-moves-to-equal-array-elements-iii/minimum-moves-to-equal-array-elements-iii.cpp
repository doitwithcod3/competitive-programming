class Solution {
public:
    const int inf = 1e9;
    int minMoves(vector<int>& nums) {
        int n = nums.size(), maxele = -inf, sum = 0;
        for (auto &ele : nums) {
            maxele = max(maxele, ele);
            sum += ele;
        }
        return maxele * n - sum;
    }
};