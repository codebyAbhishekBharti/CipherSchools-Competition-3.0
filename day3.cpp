#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
Node* make(int n){
    if(n==0) return NULL;
    int data;
    cin >> data;
    Node* head=new Node(data);
    Node* tail=head;
    for(int i=1;i<n;i++)
    {
        cin >> data;
        Node* nn=new Node(data);
        tail->next=nn;
        tail=nn;
    }
    return head;
}
void reorderList(Node* head) {
    if (!head || !head->next || !head->next->next) {
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* prev = NULL;
    Node* curr = slow->next;
    slow->next = NULL;
    while (curr) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    Node* first = head;
    Node* second = prev;
    while (second) {
        Node* temp1 = first->next;
        Node* temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}

void print(Node* head){
    while(head){
        cout << head->data << ' ';
        head=head->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    /* 
    Input format
    7                     -no. of element in the linkedlist
    17 15 8 9 2 4 6       -elements of linkedlist
    */
    int n;
    cin >> n;
    Node* head=make(n);
    reorderList(head);
    print(head);
    return 0;
}