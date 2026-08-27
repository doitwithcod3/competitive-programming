/* Problem Link:
    https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
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

void insertNext(int ele, ListNode* &head) {
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

void insertBottom(int ele, ListNode* &head) {
    ListNode* node = new ListNode(ele);
    
    if (head == NULL) {
        head = node;
        return;
    }

    ListNode* iter = head;
    while (iter -> bottom != NULL) {
        iter = iter -> bottom;
    }
    iter -> bottom = node;
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

void printList(ListNode *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node -> val);
        Node = Node->bottom;
    }
}

class Solution {
public:
    ListNode *mergeTwo(ListNode* one, ListNode* two) {
        ListNode* result = new ListNode(0); ListNode* iter = result;
        
        while (one != NULL && two != NULL) {
            if (one -> val > two -> val) {
                iter -> bottom = two;
                two = two -> bottom;
            }
            else {
                iter -> bottom = one;
                one = one -> bottom;
            }
            iter = iter -> bottom;
        }    
        if (one) iter -> bottom = one;
        else iter -> bottom = two;
        
        return result -> bottom;
    } 

    ListNode *flatten(ListNode *root)
    {
        if (root == NULL || root -> next == NULL) return root;
       
        root -> next = flatten(root -> next);
       
        root = mergeTwo(root, root -> next);

        return root;
    }
};


// Copied from GFG int_main :)

int main() {
    
    int n,m,flag=1,flag1=1;
    ListNode * temp=NULL;
    ListNode * head=NULL;
    ListNode * pre=NULL;
    ListNode * tempB=NULL;
    ListNode * preB=NULL;
    // cout << "Enter number of Nexts (Columns)\n";
    cin>>n;
    int work[n];
    // cout << "Enter Size of each BottomList\n";
    for(int i=0;i<n;i++) cin>>work[i];
    for(int i=0;i<n;i++){
        m=work[i];
        --m;
        int data;
        scanf("%d",&data);
        temp = new ListNode(data);
        temp->next = NULL;
        temp->bottom = NULL;
        
        if(flag){
            head = temp;
            pre = temp;
            flag = 0;
            flag1 = 1;
        }
        else{
            pre->next = temp;
            pre = temp;
            flag1 = 1;
        }
        for(int j=0;j<m;j++){
            
            int temp_data;
            scanf("%d",&temp_data);
            tempB = new ListNode(temp_data);

            if(flag1){
                temp->bottom=tempB;
                preB=tempB;
                flag1=0;
            }
            else{
                preB->bottom=tempB;
                preB=tempB;
            }
        }
    }
    Solution s;
    ListNode* root = s.flatten(head);
    printList(root);
    cout<<endl;

    return 0;
}