/* Problem Link:
    https://leetcode.com/problems/permutation-sequence
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> a(n, 0);
        int fact = 1;
        for (int i = 1; i <= n; ++i) {
            a[i-1] = i;
            fact *= i;
        }
        string result;
        while (true) {
            if (a.size() == 0) break;
            fact /= a.size();
            int index = (k-1) / fact;
            // cout << index << " ";
            k = k - (fact*index);
            result += (char) ('0' + a[index]);
            a.erase(a.begin() + index);
        }
        return result;
    }
};

int main() {
    Solution s;

    int n, k; cin >> n >> k;
    cout << s.getPermutation(n, k) << endl;
}