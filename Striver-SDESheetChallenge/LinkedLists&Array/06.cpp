/* Problem Link:
    https://leetcode.com/problems/max-consecutive-ones
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0, temp = 0;    
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) ++temp;
            else temp = 0;

            result = max(temp, result);
        }
        return result;
    }   

};

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Solution s;
    cout << s.findMaxConsecutiveOnes(a) << endl;

}