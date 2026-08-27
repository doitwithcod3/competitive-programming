/* Problem Link:
    https://leetcode.com/problems/rotate-list/
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next, *bottom;

    ListNode(int x = 0){
        val = x;
        next = NULL;
        bottom = NULL;
    }
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
    int ele = 0;
    while (temp != NULL) {
        if (ele > 30){
            cout << " and so on ...";
            break;
        } 
        cout << temp -> val << " ";
        temp = temp -> next;

        ++ele;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head -> next == NULL) return head;
        
        ListNode* iter = head;
        int size = 0;
        while (iter != NULL) {
            ++size;
            iter = iter -> next;
        }
        k = k % size; 
        int travel = size - k - 1;

        // Making list circular :)
        iter = head;
        while (iter -> next != NULL) iter = iter -> next;
        iter -> next = head;

        // Going to last node after Rotation
        ListNode* prev = head, *nex = head;
        while (travel--) {
            prev = prev -> next;
        }
        nex = prev -> next;
        prev -> next = NULL;
        return nex;
    }
};

int main() {
    int n, k; cin >> n >> k;
    ListNode* head = new ListNode(0);
    for (int i = 0; i < n; ++i) {
        int ele; cin >> ele;
        insert(ele, head);
    }
    Solution s;
    auto it = s.rotateRight(head -> next, k);
    display(it);
    return 0;
}
