
// Question Link -
// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool peak(int i, vector<int> &a) {
        int n = a.size(); 
        if (n == 1) return false;
        if (i == 0) return (a[i] >= a[i+1]);
        if (i == n-1) return (a[i-1] < a[i]);
        
        return (a[i-1] < a[i] && a[i] >= a[i + 1]);
    }
    
    int stockBuyAndSell(int n, vector<int> &a) {
        int profit = 0, mini = INT_MAX;
        for (int i = 0; i < n; ++i) {
            mini = min(a[i], mini);
            
            if (peak(i, a)) {
                profit += max(a[i] - mini, 0);
                mini = INT_MAX;
            }
        }
        return profit;
    }
};

int main() {
    Solution s;
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << s.stockBuyAndSell(n, a) << endl;
}

