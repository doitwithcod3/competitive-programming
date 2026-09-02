class Solution {
public:
    const int inf = 1e9;
    map<int, int> findall(int num, int maxval) {
        map<int, int> res;
        int temp = num, iteration = 0;
        while (temp) {
            if (temp <= maxval) {
                if (res.find(temp) != res.end()) res[temp] = min(res[temp], iteration);
                else res[temp] = iteration;
            }
            temp >>= 1;
            ++iteration;
        }
        temp = num, iteration = 0;
        while (temp <= maxval) {
            if (res.find(temp) != res.end()) res[temp] = min(res[temp], iteration);
            else res[temp] = iteration;
            temp <<= 1;
            ++iteration;
        }
        return res;
    }

    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector dp(n + 1, vector<int> (sum + 1, inf));
        dp[0][0] = 0;
        for (int index = 1; index <= n; ++index) {
            dp[index][0] = 0;
            for (auto it : findall(nums[index - 1], sum)) {
                int num = it.first, val = it.second;
                for (int s = 1; s <= sum; ++s) {
                    if (0 <= s - num) dp[index][s] = min(dp[index][s], dp[index - 1][s - num] + val);
                    dp[index][s] = min(dp[index][s], dp[index - 1][s]);
                }
            }
        }
        return dp[n][sum] >= inf ? -1 : dp[n][sum];
    }
};