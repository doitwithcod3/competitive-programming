/* Problem Link:
    https://leetcode.com/problems/unique-paths/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int R = min(m, n) - 1;

        double result = 1;
        for (int i = 1; i <= R; ++i) {
            result = result * (N - i + 1) / i;
        }
        return (int) result;
    }
};

int main() {
    Solution s;
    int m, n; cin >> m >> n;
    cout << s.uniquePaths(m, n) << endl;
}