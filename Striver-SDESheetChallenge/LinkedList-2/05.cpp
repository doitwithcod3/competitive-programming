/* Problem Link:
    https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) return NULL;
        ListNode* slow = head, *fast = head;
        ListNode* result = head;

        while (fast -> next != NULL && fast -> next -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) {
                while (result != slow) {
                    result = result -> next;
                    slow = slow -> next;
                }
                return result;
            }
        }   
        return NULL;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode();
    cout << "Enter no of Linear Elements\n";
    int n; cin >> n;
    
    cout << "Enter " << n << " Elements\n";
    for (int i = 0; i < n; ++i) {
        int ele; cin >> ele;
        insert(ele, head);
    }

    cout << "Enter no of Circular Elements\n";
    int m; cin >> m;
    
    ListNode* circular = new ListNode();
    cout << "Enter " << m << " Elements\n";
    for (int i = 0; i < m; ++i) {
        int ele; cin >> ele;
        insert(ele, circular);
    }

    // Making it Circular.
    ListNode* end = circular;
    while (end -> next != NULL) end = end -> next;
    end -> next = circular -> next;


    // Merging both LL
    end = head;
    while (end -> next != NULL) end = end -> next;
    end -> next = circular -> next;

    cout << s.detectCycle(head) -> val << endl;

}