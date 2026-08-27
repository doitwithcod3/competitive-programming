/* Problem Link:
    https://leetcode.com/problems/merge-two-sorted-lists/
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

    void insert(int ele, ListNode* &head, ListNode* &tail) {
        ListNode* node = new ListNode(ele);
        tail -> next = node;
        tail = tail -> next;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode();
        ListNode* ins = head;

        ListNode* i = list1;
        ListNode* j = list2;

        while (i != NULL && j != NULL) {
            if (i -> val > j -> val) {
                insert(j -> val, head, ins);
                j = j -> next;
            }
            else {
                insert(i -> val, head, ins);
                i = i -> next;
            }
        }
        
        while (i != nullptr) {
            insert(i -> val, head, ins);
            i = i -> next;
        }

        while (j != nullptr) {
            insert(j -> val, head, ins);
            j = j -> next;
        }
        return head -> next;
    }
};

int main() {
    Solution s;
    ListNode *l1 = NULL, *l2 = NULL;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int ele; cin >> ele;
        insert(ele, l1);
    }
    for (int i = 0; i < m; ++i) {
        int ele; cin >> ele;
        insert(ele, l2);
    }

    auto it = s.mergeTwoLists(l1, l2);

    display(it);
    
}