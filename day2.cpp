#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data):data(data),next(NULL){};
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
void print(Node* head){
    while(head){
        cout << head->data << ' ';
        head=head->next;
    }
    cout << endl;
}
Node* rearrange(Node* head){
    Node* odd = NULL;
    Node* even = NULL;
    Node* new_even = NULL;
    Node* new_odd = NULL;
    
    while (head){
        if (head->data % 2 == 0){
            if (!new_even) {even = head;new_even = head;}
            else {even->next = head;even = head;}
        } 
        else{
            if (!new_odd) {odd = head;new_odd = head;}
            else {odd->next = head;odd = head;}
        }
        head = head->next;
    }
    
    if(even) even->next = new_odd;
    else new_even = new_odd;
    if(odd) odd->next = NULL;
    return new_even;
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
    head=rearrange(head);
    print(head);
    return 0;
}
