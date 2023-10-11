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
int total_component(Node* head, vector<int>& nums) {
    map<int,int> mp ;
    for (auto i :nums)
        mp[i]++;
    Node* temp = head;
    int ans = 0;
    while(temp)
    {
        if(mp[temp->data] !=0 )
        {
            while(temp->next && mp[temp->next->data] != 0 )
            {
                temp = temp->next;
            }
            ans++;
        }
        temp = temp->next;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    /* 
    Input format
    4             -no. of element in the linkedlist
    0 1 2 3       -elements of linkedlist
    3             -no. of element in the nums
    0 1 3         -elements of nums
    */
    int n;
    cin >> n;
    Node* head=make(n);
    cin >> n;
    vector<int>v(n);
    for(auto i=0;i<n;i++) cin >> v[i];
    cout <<total_component(head,v);
    return 0;
}
