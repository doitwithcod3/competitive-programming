/* Problem Link:
    https://practice.geeksforgeeks.org/problems/subset-sums2234/1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void makeSubsetSum(int ind, int sum, vector<int>& ar, vector<int>& res) {
        if (ind == (int) ar.size()){
            res.push_back(sum);
            return;
        } 
        
        makeSubsetSum(ind + 1, sum + ar[ind], ar, res);
        
        makeSubsetSum(ind + 1, sum, ar, res);
    }
    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> result;
        makeSubsetSum(0, 0, arr, result);
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Solution s;
    
    auto res = s.subsetSums(a, n);
    for (auto it : res) cout << it << " "; cout << endl;
}
