/* QuestionLink
	https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            profit = max(profit, prices[i] - mini);
            mini = min(prices[i], mini); 
        }
        return profit;
    }
};

// Main for Testing Inputs :) 
int main() { 
	Solution s;
	int n; cin >> n; vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	cout << s.maxProfit(a) << endl;
}
