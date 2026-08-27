/* Problem Link:
    https://leetcode.com/problems/intersection-of-two-linked-lists/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA, * b = headB;

        while (a != b) {
            if (a == NULL) a = headB; 
            else a = a -> next;
            if (b == NULL) b = headA;
            else b = b -> next;
        }   
        return a; 
    }
};

int main() {
    Solution s;
    ListNode *l1 = NULL, *l2 = NULL, *a = l1, *b = l2;

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

    // Creating Y between both the LLs
    while (a != NULL && a -> next != NULL) a = a -> next;

    if (b != NULL && b -> next != NULL) b = b -> next; 

    a -> next = b;

    cout << "List1 = "; display(l1);
    cout << "List2 = "; display(l2);


    // My main is not Running unfortunately...
    // Uploading with just FUNCTION WRITTEN IN LEETCODE
    
    auto it = s.getIntersectionNode(l1, l2);

    cout << it -> val << endl;
    
}
