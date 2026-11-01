/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        Node* pre=head;
        Node* curr=head->next;
        Node* nxt=NULL;
         pre->next=NULL;
        while(curr!=NULL)
         {
             nxt=curr->next;
             pre->prev=curr;
             curr->prev=nxt;
             curr->next=pre;
             pre=curr;
             curr=nxt;
             
         }        
         pre->prev=NULL;
        
         return pre;
    }
};