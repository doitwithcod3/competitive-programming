/* Problem Link:
    https://leetcode.com/problems/single-element-in-a-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int i = 0, j = a.size() - 2;
        while (i <= j) {
            int mid = (i+j) >> 1;
            if (mid % 2 == 0 && a[mid] == a[mid+1]) i = mid + 1; 
            else if (mid % 2 == 1 && a[mid] == a[mid-1]) i = mid + 1;
            else  j = mid - 1;
        }
        return a[i];
    }
};

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Solution s;
    cout << s.singleNonDuplicate(a) << endl;
}