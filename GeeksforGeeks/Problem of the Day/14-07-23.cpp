// Question Link-
// https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

#include <bits/stdc++.h>
using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
    public:
    
    twoStacks(int n=100)
    {
        size = n; 
        arr = new int[n]; 
        top1 = -1; 
        top2 = size;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        arr[++top1] = x;
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {   
        arr[--top2] = x;   
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 == -1) return -1;
        return (arr[top1--]);
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 == size) return -1;
        return arr[top2++];
    }
};

int main() {
    twoStacks st1;
    cout << "Enter Elements to Push in Stack1 and Stack2\n";
    int n, m; cin >> n >> m;
    cout << "Enter " << n << " Elements\n";
    for (int i = 0; i < n; ++i) {
        int ele; cin >> ele;
        st1.push1(ele);
    }
    cout << "Enter " << m << " Elements\n";
    for (int i = 0; i < m; ++i) {
        int ele; cin >> ele;
        st1.push2(ele);
    }

    cout << "Removing all Elements from Stack1 : ";
    while (true) {
        int ele = st1.pop1();
        if (ele == -1) break;
        else cout << ele << " ";
    }
    cout << endl; 

    cout << "Removing all Elements from Stack2 : ";
    while (true) {
        int ele = st1.pop2();
        if (ele == -1) break;
        else cout << ele << " ";
    }
    cout << endl;
}