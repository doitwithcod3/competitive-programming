/* Problem Link:
    https://leetcode.com/problems/majority-element/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Basic Approach 
    int majorityElementBasic(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }    
        int maxFreq = 0, maxEle = -1;
        for (auto it : m) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                maxEle = it.first;
            }
        }
        return maxEle;
    }

    // Expected Solution (Moore's Voting Algo)
    int majorityElement(vector<int>& nums) {
        int count = 0, ele;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                count++;
                ele = nums[i];
            }
            else if (nums[i] == ele) count++;
            else --count;
        }

        return ele;
    }

};

int main() {
    Solution s;
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << s.majorityElementBasic(a) << endl;

    cout << s.majorityElement(a) << endl;
}