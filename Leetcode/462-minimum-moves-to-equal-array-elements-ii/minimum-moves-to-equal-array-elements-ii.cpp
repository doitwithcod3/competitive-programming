// find median
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (auto &ele : nums) {
            ans += abs(ele - nums[(n >> 1)]);
        }
        return ans;
    }
};