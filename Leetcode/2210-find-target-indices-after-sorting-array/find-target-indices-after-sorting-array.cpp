class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        int count = ub - lb, lowest = lb - nums.begin();
        vector<int> ans(count);
        iota(ans.begin(), ans.end(), lowest);
        return ans;
        
    }
};