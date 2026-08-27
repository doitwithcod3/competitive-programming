/* Problem Link:
    https://leetcode.com/problems/majority-element/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> a;
        for (int i = 0; i < (int) nums.size(); ++i) {
            a.insert(nums[i]);
        }
        int count = INT_MIN, result = 0;
        for (auto it : a) {
            if (a.find(it-1) == a.end()) {
                count = 1;
                int digit = it;
                while (a.find(++digit) != a.end()) ++count;
            }
            result = max(result, count);
        }
        return result;
         
    }
};

int main() {
    Solution s;
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << s.longestConsecutive(a) << endl;
}