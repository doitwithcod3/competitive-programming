/* Problem Link:
    https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;

        while (i <= j) {
            int mid = (i + j) >> 1;
            if (nums[mid] == target) return mid;

            // mid = 7, target = 0, arr[0] = 4     4 5 6 7 0 1 2
            if (nums[i] <= nums[mid]) {
                if (nums[i] <= target && target < nums[mid]) j = mid - 1;
                else  i = mid + 1;
            }
            else {
                if (nums[j] < target || nums[mid] > target) j = mid - 1;
                else i = mid + 1; 
            }
        }    
        return -1;
    }
};

int main() {
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Solution s;
    cout << s.search(a, t) << endl;
}