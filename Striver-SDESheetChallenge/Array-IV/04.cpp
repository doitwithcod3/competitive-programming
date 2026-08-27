/* Problem Link:
    https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        unordered_map<int, int> s;
        int result = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (sum == 0) result = max(result, i+1);
            if (s.find(sum) == s.end()) {
                s[sum] = i;
            }
            else {
                result = max(result, i - s[sum]);
            }
        } 
        // cout << endl;
        return result;
    }
};

int main() {
    Solution s;
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << s.maxLen(a, n) << endl;
}