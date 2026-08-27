/* Problem Link:
    https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> result;
        while (N) {
            if (N >= 2000) {
                N-= 2000;
                result.push_back(2000);
            }
            else if (N >= 500) {
                N-= 500;
                result.push_back(500);
            }
            else if (N >= 200) {
                N-= 200;
                result.push_back(200);
            }
            else if (N >= 100) {
                N-= 100;
                result.push_back(100);
            }
            else if (N >= 50) {
                N -= 50;
                result.push_back(50);
            }
            else if (N >= 20) {
                N -= 20;
                result.push_back(20);
            }
            else if (N >= 10) {
                N -= 10;
                result.push_back(10);
            }
            else if (N >= 5) {
                N-= 5;
                result.push_back(5);
            }
            else if (N >= 2) {
                N-= 2;
                result.push_back(2);
            }
            else {
                N--;
                result.push_back(1);
            }
        }
        return result;
    }
};

int main() {
    int n; cin >> n;
    Solution s;
    auto res = s.minPartition(n);

    for (auto it : res) cout << it << " "; cout << endl;
}