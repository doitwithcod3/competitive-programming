// Question Link-
// https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Taking Space O(n).
    public:
    int _missingNumber(int arr[], int n) 
    { 
        vector<bool> a(n+2, 0);
        for (int i = 0; i < n; ++i) {
            if (0 <= arr[i] && arr[i] <= n) a[arr[i]] = 1;
        }
        for (int i = 1; i < a.size(); ++i) {
            if (!a[i]) return i;
        } 
        return -1;
    } 

    // Taking O(1) space
    int missingNumber(int arr[], int n) 
    { 
        // creating space to store multiple digit in one..
        for (int i = 0; i < n; ++i) {
            arr[i] *= 1000;
        }
        
        // Increamenting the index which is Already in array..
        for (int i = 0; i < n; ++i) {
            int actualNumber = arr[i] / 1000;
            if (1 <= actualNumber && actualNumber <= n) {
                ++arr[actualNumber-1];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (arr[i] % 1000 == 0) return i+1;
        }
        return n+1;
    } 

};


int main() {
    Solution s;
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << s.missingNumber(a, n) << endl;
    
}
