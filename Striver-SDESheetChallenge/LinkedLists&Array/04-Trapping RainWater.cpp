/* Problem Link:
    https://leetcode.com/problems/trapping-rain-water/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int i = 0, j = n - 1;
        int maxFront = 0, maxBack = 0, result = 0;
        while (i <= j) {
            if (a[i] <= a[j]) {
                if (a[i] < maxFront)
                    result += maxFront - a[i];
                else maxFront = max(maxFront, a[i]);
                i++;
            }
            else {
                if (a[j] > maxBack) maxBack = max(a[j], maxBack);
                else result += maxBack - a[j];
                j--;
            }
        }        
        return result;
    }
};

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Solution s;

    cout << s.trap(a) << endl;
}