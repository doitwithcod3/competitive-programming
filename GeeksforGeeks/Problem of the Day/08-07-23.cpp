// Question Link-
// https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int a[], int n)
    { 
        //Your code here
        sort(a, a+n);
        for (int i = 0; i < n; ++i) {
            int req = -1 * a[i];
            int beg = i + 1, end = n - 1;
            while (beg < end) {
                int sum = a[beg] + a[end];
                if (sum == req) return true;
                else if (sum < req) ++beg;
                else --end;
            }
        }
        return false;
        
    }
};

int main() {
    Solution s;
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << s.findTriplets(a, n) << endl;
    
}
