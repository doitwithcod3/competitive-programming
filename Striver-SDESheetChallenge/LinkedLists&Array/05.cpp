/* Problem Link:
    https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int i = 0;

        for (int j = 1; j < a.size(); ++j) {
            if (a[i] != a[j]) a[++i] = a[j];
        }
        return i+1;
    }
};

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Solution s;

    int size = s.removeDuplicates(a);
    for (int i = 0; i < size; ++i) cout << a[i] << " "; cout << endl;
}