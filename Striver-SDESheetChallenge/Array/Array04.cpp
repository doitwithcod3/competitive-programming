/* QuestionLink
	https://leetcode.com/problems/maximum-subarray/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            result = max(result, sum);
            sum = max(0, sum);
        }
        return result;
    }
};

// Main for Testing Inputs :) 
int main() { 
	Solution s;
	int n; cin >> n; vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	cout << s.maxSubArray(a) << endl;
}
