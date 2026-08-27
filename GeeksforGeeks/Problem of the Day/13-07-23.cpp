// Question Link-
// https://practice.geeksforgeeks.org/problems/unique-frequencies-of-not/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool isFrequencyUnique(int n, int a[])
    {
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m[a[i]]++;
        }
        map<int, int> result;
        for (auto i : m) result[i.second]++;
    
        for (auto i : result) {
            if (i.second != 1) return false;
        }
        return true;
    }
    
};

int main() {
    Solution s;
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (s.isFrequencyUnique(n, a)) cout << "YES\n";
    else cout << "NO\n";
}
