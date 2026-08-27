/* QuestionLink
    https://www.codingninjas.com/codestudio/problems/873366?topList=striver-sde-sheet-problems
*/

#include <bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        ++a[arr[i] - 1];
    } 
    int missing = -1, repeating = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) missing = i + 1;
        if (a[i] == 2) repeating = i + 1;
    }
    return make_pair(missing, repeating);
    
}

// Main for Testing Inputs :) 
int main() { 
	int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    auto result = missingAndRepeating(a, n);

    cout << result.first << " " << result.second << endl;
}