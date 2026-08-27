// Question Link-
// https://practice.geeksforgeeks.org/problems/quick-sort/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low < high) {
            int par = partition(arr, low, high);
            
            // for (int i : arr) cout << i << " "; cout << endl;
            quickSort(arr, low, par - 1);
            quickSort(arr, par + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[low];
        int i = low, j = high;
        while (i < j) {
            while (arr[i] <= pivot && i <= high - 1) i++;
            
            while (arr[j] > pivot && low + 1 <= j) j--;
            
            if (i < j) swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }
};

int main() {
    Solution s;
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i) cin >> a[i];

    s.quickSort(a, 0, n);

    for (int i = 0; i < n; ++i) cout << a[i] << " "; cout << endl;
    
}
