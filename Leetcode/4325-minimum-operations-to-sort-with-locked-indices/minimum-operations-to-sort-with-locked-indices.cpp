class Solution {
public:
    /*
        first we will create a vector of pairs which will contain a range which is required to be swapped.
        if we have sufficient keys (k) for locked nums in range, we will calculate swap, else return -1.
    */
    const int inf = 1e9;
    
    int countinversion(int start, int end, vector<int>& nums) {
        int ans = 0;
        for (int i = start; i <= end; ++i) {
            for (int j = i + 1; j <= end; ++j) {
                if (nums[i] > nums[j]) ans++;
            }
        }
        return ans;
    }

    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        vector<pair<int, int>> ranges;
        vector<int> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && nums[i] != i + 1) {
                int expectedindex = nums[i] - 1;
                int mini = inf, maxi = -inf;
                int iterator = i;
                while (iterator <= expectedindex) {
                    visited[iterator] = true;
                    mini = min(mini, iterator);
                    maxi = max(maxi, iterator);
                    expectedindex = max(expectedindex, nums[iterator] - 1);
                    iterator++;
                }
                ranges.push_back({mini, maxi});
            }
        } 
        int needed = 0;
        int ans = 0;
        for (auto [start, end] : ranges) {
            cout << start << " " << end << endl;
            for (int i = start; i <= end; ++i) {
                needed += locked[i] == 1;
            }
            ans += countinversion(start, end, nums);
        }
        if (needed > k) return -1;
        return ans + needed;
    }
};