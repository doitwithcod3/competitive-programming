class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> smin(n);
        int maxsofar = -1;
        for (int i = 0; i < n; ++i) {
            if (i == 0) smin[n - i - 1] = nums[n - i - 1];
            else smin[n - i - 1] = min(smin[n - i], nums[n - i - 1]);
        }
        for (int i = 0; i < n; ++i) {
            maxsofar = max(maxsofar, nums[i]);
            if (maxsofar - smin[i] <= k) return i;
        }
        return -1;
    }
};