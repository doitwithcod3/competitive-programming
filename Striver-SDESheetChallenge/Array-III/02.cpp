/* Problem Link:
    https://leetcode.com/problems/powx-n/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long a = abs((long long) n);
        double res = 1;
        while (a) {
            if (a % 2 == 0) {
                x = x * x;
                a /= 2;
            }
            else {
                res = res * x;
                a--;
            }
        }
        if (n >= 0) return res;
        return 1/res;
    }
};

int main() {
    Solution s;
    double base; int power;
    cin >> base >> power;
    cout << s.myPow(base, power) << endl;
}