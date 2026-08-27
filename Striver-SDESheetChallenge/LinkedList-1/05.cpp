/* Problem Link:
    https://leetcode.com/problems/add-two-numbers/
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

void insert(int ele, ListNode* &head) {
    ListNode* node = new ListNode(ele);
    
    if (head == NULL) {
        head = node;
        return;
    }

    ListNode* iter = head;
    while (iter -> next != NULL) {
        iter = iter -> next;
    }
    iter -> next = node;
}

void display(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);

        ListNode* it1 = l1, *it2 = l2, *add = result; 
        int carry = 0, sum = 0;
        while (it1 != NULL && it2 != NULL) {
            sum = it1 -> val + it2 -> val + carry;
            carry = sum/10; sum %= 10; 
            add -> next = new ListNode(sum);

            add = add -> next;
            it1 = it1 -> next;
            it2 = it2 -> next;
        }
        while (it1 != NULL) {
            sum = it1 -> val + carry;
            carry = sum/10; sum %= 10;
            cout << carry << " " << sum << endl; 
            
            add -> next = new ListNode(sum);

            add = add -> next;
            it1 = it1 -> next;
        }
        while (it2 != NULL) {
            sum = it2 -> val + carry;
            carry = sum/10; sum %= 10;
            add -> next = new ListNode(sum);

            add = add -> next;
            it2 = it2 -> next;
        }
        if (carry != 0) 
            add -> next = new ListNode(carry);

        return result -> next;
    }
};

int main() {
    Solution s;
    ListNode *list1 = NULL, *list2 = NULL;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int ele; cin >> ele;
        insert(ele, list1);
    }

    for (int i = 0; i < m; ++i) {
        int ele; cin >> ele;
        insert(ele, list2);
    }

    auto it = s.addTwoNumbers(list1, list2);

    display(it);
    
}