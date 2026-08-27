/* Problem Link:
    https://leetcode.com/problems/3sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& ar) {
        vector<vector<int>> result;
        int n = ar.size();
        sort(ar.begin(), ar.end());

        for (int i = 0; i < n-2; ++i) {
            int a = i+1, b = n-1;
            while (a < b) {
                if (ar[i] + ar[a] + ar[b] > 0) {
                    b--;
                    while (a < b && ar[b] == ar[b+1]) --b;    
                }
                else if (ar[i] + ar[a] + ar[b] < 0) {
                    a++;
                    while (a < b && ar[a] == ar[a-1]) a++;
                }
                else {
                    vector<int> temp = {ar[i], ar[a], ar[b]};
                    result.push_back(temp);
                    a++;
                    b--;
                    while (a < b && ar[a] == ar[a-1]) ++a;
                    while (a < b && ar[b] == ar[b+1]) --b;
                }
            }

            while (i < n-1 && ar[i] == ar[i+1]) i++;
        }  
        return result;  
    }
};

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Solution s;

    auto it = s.threeSum(a);
    for (auto i : it) {
        for (int a : i) cout << a << " "; cout << endl;
    } 
}