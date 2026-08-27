/* QuestionLink
	https://www.codingninjas.com/codestudio/problems/count-inversions_615
*/

#include <bits/stdc++.h> 
using namespace std;

long long counter = 0;

void merge(long long *arr, int beg, int mid, int end) {
    int i = beg, j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= end) {
        if (arr[i] > arr[j]) {
            temp.push_back(arr[j++]);
            counter += (mid-i+1);
        }
        else { 
            temp.push_back(arr[i++]);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= end) {
        temp.push_back(arr[j++]);    
    }

    for (int i = beg; i <= end; ++i) {
        arr[i] = temp[i-beg];
    }
}

void mergeSort(long long *arr, int beg, int end) {
    if (beg == end) return;
    int mid = (beg + end)/2;
    mergeSort(arr, beg, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, beg, mid, end);
}

long long getInversions(long long *arr, int n){
    mergeSort(arr, 0, n-1);
    return counter;
}

// Main for Testing Inputs :) 
int main() { 
    int n; cin >> n;
    long long arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    cout << getInversions(arr, n);
}
