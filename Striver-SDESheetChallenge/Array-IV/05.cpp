/* Problem Link:
    https://www.interviewbit.com/problems/subarray-with-given-xor/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &a, int B) {
        map<int, int> m;
        int xr = 0;
        m[xr] = 1;
        int result = 0;
        for (int i = 0; i < a.size(); ++i) {
            xr = (xr ^ a[i]);
            int f = (B ^ xr);
            if (m.find(f) != m.end()) result += m[f];
            m[xr]++;
        }
        return result;
    }
};


int main() {
    Solution s;
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int xr; cin >> xr;

    cout << s.solve(a, xr) << endl;
}