/* Problem Link:
    https://leetcode.com/problems/reverse-pairs/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result = 0;
    void merge(vector<int> &nums, int beg, int mid, int end) {
        int i = beg, j = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= end) {
            if (nums[i] < nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]); 
        }
        while (i <= mid) {
            temp.push_back(nums[i++]);
        }
        while (j <= end) {
            temp.push_back(nums[j++]);
        }

        for (int i = beg; i <= end; ++i) {
            nums[i] = temp[i-beg];
        }
    }
    // Adjusted Logic 
    void calculate(vector<int> &nums, int beg, int mid, int end) {
        int i = beg, j = mid + 1;
        while (j <= end && i <= mid) {
            if (1LL * nums[i] <= 2 * 1LL * nums[j]) {
                i++;
            }
            else {
                result += (mid-i+1);
                j++;
            }
        }
    }

    void mergeSort(vector<int> &nums, int beg, int end) {
        if (beg == end) return;
        int mid = (beg + end)/2;

        mergeSort(nums, beg, mid);
        mergeSort(nums, mid+1, end);
        calculate(nums, beg, mid, end);
        merge(nums, beg, mid, end);
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return result;
    }
};

int main() {
    Solution s;
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    cout << s.reversePairs(a) << endl;
}