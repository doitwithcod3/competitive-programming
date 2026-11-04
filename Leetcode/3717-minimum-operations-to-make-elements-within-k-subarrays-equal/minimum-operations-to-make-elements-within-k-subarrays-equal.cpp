class Solution {
public:
    const long long inf = 1e16;
    multiset<long long> leftset, rightset;
    long long leftsum = 0, rightsum = 0;
    int balancesize;

    void balance() {
        while (leftset.size() > balancesize) {
            auto it = prev(leftset.end());
            long long val = *it;
            leftsum -= val;
            leftset.erase(it);

            rightset.insert(val);
            rightsum += val;
        }
        while (leftset.size() < balancesize && !rightset.empty()) {
            auto it = rightset.begin();
            long long val = *it;
            rightsum -= val;
            rightset.erase(it);

            leftset.insert(val);
            leftsum += val;
        }
    }

    void add(long long val) {
        if (leftset.empty() || val <= *leftset.rbegin()) {
            leftset.insert(val);
            leftsum += val;
        } else {
            rightset.insert(val);
            rightsum += val;
        }
        balance();
    }

    void remove(long long val) {
        auto it = leftset.find(val);
        if (it != leftset.end()) {
            leftsum -= val;
            leftset.erase(it);
        } else {
            auto rightindex = rightset.find(val);
            rightsum -= val;
            rightset.erase(rightindex);
        }
        balance();
    }

    long long getcost() {
        long long median = *leftset.rbegin();
        long long leftcost = (long long)leftset.size() * median - leftsum;
        long long rightcost = rightsum - (long long)rightset.size() * median;
        return leftcost + rightcost;
    }

public:
    long long minOperations(vector<int>& nums, int m, int k) {
        int n = nums.size();
        balancesize = (m + 1) / 2;
        leftsum = 0;
        rightsum = 0;
        leftset.clear();
        rightset.clear();

        int winsize = n - m + 1;
        vector<long long> cost(winsize, 0);

        for (int i = 0; i < m; ++i) {
            add(nums[i]);
        }
        cost[0] = getcost();

        for (int i = m; i < n; ++i) {
            remove(nums[i - m]);
            add(nums[i]);
            cost[i - m + 1] = getcost();
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, inf));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= k; ++j) {
            for (int i = n - 1; i >= 0; --i) {
                dp[i][j] = dp[i + 1][j];

                if (i + m <= n) {
                    long long pick = cost[i] + dp[i + m][j - 1];
                    dp[i][j] = min(dp[i][j], pick);
                }
            }
        }

        return dp[0][k];
    }
};