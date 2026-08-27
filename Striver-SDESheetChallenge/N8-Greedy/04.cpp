/* Problem Link:
    https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;

class Item {
public:
    int value, weight;
};

class Solution {
    public:
    static bool compare(Item a, Item b) {
        return ((a.value*1.0)/a.weight > (b.value*1.0)/b.weight); 
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        if (n > 1) sort(arr, arr + n, compare);
        double result = 0;
        for (int i = 0; i < n && W > 0; ++i) {
            int ww = min(arr[i].weight, W);
            W -= ww;
            result += ww*(arr[i].value*1.0)/arr[i].weight;
        }
        return result;
    }
        
};

int main() {
    int n, W; cin >> n >> W;
    Item arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].value >> arr[i].weight; 
    }
    Solution s;
    cout << s.fractionalKnapsack(W, arr, n);
}
