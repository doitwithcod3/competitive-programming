/* Problem Link:
    https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findPlatform(int arr[], int dep[], int n) {
        sort(arr, arr + n);
        sort(dep, dep + n);
        
        int i = 1, j = 0, platform  = 1, result = 0;
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                ++platform; ++i;
            }
            else {
                --platform; ++j;
            }
            result = max(result, platform);
        }
        return result;
    }
};

int main() {
    int n; cin >> n;
    int arr[n], dep[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i] >> dep[i];
    }
    Solution s;
    cout << s.findPlatform(arr, dep, n) << endl;
}