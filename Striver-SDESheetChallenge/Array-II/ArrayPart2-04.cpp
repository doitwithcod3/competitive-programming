/* QuestionLink
	https://leetcode.com/problems/find-the-duplicate-number/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> a(nums.size());
        for (int i = 0; i < a.size(); ++i) {
            ++a[nums[i]];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (a[i] > 1) return i;
        }
        return -1;
    }
};

// Main for Testing Inputs :) 
int main() { 
	Solution s;
	int n; cin >> n; vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

    cout << s.findDuplicate(a) << endl;
}