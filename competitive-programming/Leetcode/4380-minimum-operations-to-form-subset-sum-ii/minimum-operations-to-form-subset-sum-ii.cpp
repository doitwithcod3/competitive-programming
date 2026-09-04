class Solution {
public:
    const int inf = 1e9;
    
    void dfs(int current, int maxval, int iteration, map<int, int> &res) {
        if (0 >= current) return;
        if (current > maxval) return dfs(current / 2, maxval, iteration + 1, res); 
        
        if (res.find(current) != res.end()) {
            if (res[current] < iteration) return;
        }
        res[current] = iteration;
        dfs(current / 2, maxval, iteration + 1, res);
        dfs(current * 2, maxval, iteration + 1, res);
    }

    map<int, int> findall(int num, int maxval) {
        map<int, int> res;
        dfs(num, maxval, 0, res);
        return res;
    }

    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector dp(n + 1, vector<int> (sum + 1, inf));
        dp[0][0] = 0;
        for (int index = 1; index <= n; ++index) {
            dp[index] = dp[index - 1];
            for (auto it : findall(nums[index - 1], sum)) {
                int num = it.first, val = it.second;
                for (int s = num; s <= sum; ++s) {
                    dp[index][s] = min(dp[index][s], dp[index - 1][s - num] + val);
                }
            }
        }
        return dp[n][sum] >= inf ? -1 : dp[n][sum];
    }
};