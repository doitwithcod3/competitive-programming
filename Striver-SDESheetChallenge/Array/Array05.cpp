/* QuestionLink
    https://leetcode.com/problems/sort-colors/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) ++count0;
            else if (nums[i] == 1) ++count1;
            else ++count2; 
        } 

        int index = -1;
        for (int i = 0; i < count0; ++i) {
            nums[++index] = 0;
        } 
        for (int i = 0; i < count1; ++i) {
            nums[++index] = 1;
        }
        for (int i = 0; i < count2; ++i) {
            nums[++index] = 2;
        }
    }
};

// Main for Testing Inputs :) 
int main() { 
	Solution s;
	int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    s.sortColors(a);

    for (auto it : a) cout << it << " "; cout << endl;
}
