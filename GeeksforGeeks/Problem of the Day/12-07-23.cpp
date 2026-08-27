// Question Link-
// https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    const int m = 1e9 + 7;
    long long pow(int a, int b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * 1LL * a) % m;
            a = (a * 1LL * a) % m;
            b >>= 1;
        }
        return res;
    }
    long long power(int N,int R) {
        return pow(N, R);
    }

};
int main() {
    Solution s;
    int n, r; cin >> n >> r;
    cout << s.power(n, r) << endl;
}