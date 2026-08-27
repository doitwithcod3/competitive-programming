/* Problem Link:
    https://leetcode.com/problems/copy-list-with-random-pointer/
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next, *random;

    Node(int x = 0){
        val = x;
        next = NULL;
        random = NULL;
    }
    Node(int x, Node *next) : val(x), next(next) {}
};

void insert(int ele, Node* &head) {
    Node* node = new Node(ele);

    if (head == NULL) {
        head = node;
        return;
    }

    Node* iter = head;
    while (iter -> next != NULL) {
        iter = iter -> next;
    }
    iter -> next = node;
}

void display(Node* head) {
    Node* temp = head;
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
    Node* copyRandomList(Node* head) {
        Node* iter = head, *prev = head;
        while (iter != NULL) {
            iter = prev -> next;
            Node* copy = new Node(prev->val);
            prev -> next = copy;
            copy -> next = iter;
            prev = iter;
        }

        iter = head;
        while (iter != NULL) {
            if (iter -> random != NULL) {
                iter -> next -> random = iter -> random -> next;
            }
            iter = iter -> next -> next;
        }

        Node* newHead = new Node(0);

        Node* run = newHead;
        prev = head, iter = head;
        while (prev != NULL) {
            iter = prev -> next;
            run -> next = iter;
            prev -> next = iter -> next;
            run = run -> next;
            prev = iter -> next;
        }
        return newHead -> next; 
    }
};

int main() {
    int n; cin >> n;
    Node* list = new Node(0);
    for (int i = 0; i < n; ++i) {
        int ele; cin >> ele;
        insert(ele, list);
    }

    Solution s;
    auto result = s.copyRandomList(list -> next);

    display(result);
}
