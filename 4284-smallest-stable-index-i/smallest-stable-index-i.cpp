class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pmax(n);
        vector<int> smin(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                pmax[i] = nums[i];
                smin[n - i - 1] = nums[n - i - 1];
            }
            else {
                pmax[i] = max(pmax[i - 1], nums[i]);
                smin[n - i - 1] = min(smin[n - i], nums[n - i - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (pmax[i] - smin[i] <= k) return i;
        }
        return -1;
    }
};