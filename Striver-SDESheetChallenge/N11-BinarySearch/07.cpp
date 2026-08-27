// Problem Link : https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    bool check (int mid, int a[], int n, int students) {
        int stu = 1, sum = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > mid) return false;
            if (sum + a[i] > mid) {
                stu++;
                sum = a[i];
            }
            else sum += a[i];
        }
        if (stu > students) return false;
        return true;
    }
    
    int findPages(int A[], int N, int M) {
        if (N < M) return -1;
    
        int low = 0, high = 1e6 + 2;
        int ans;
        while (low <= high) {
            int mid = (low + 0ll + high) >> 1;
            // cout << low << " " << high << endl;
            if (check (mid, A, N, M)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
            
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
