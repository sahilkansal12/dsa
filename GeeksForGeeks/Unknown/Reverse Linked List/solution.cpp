/* Structure of Linked List Node
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
      Node* prev=NULL;
      Node* curr=head;
      Node* nxt=NULL;
      while(curr!=NULL)
      { 
       nxt=curr->next;
       curr->next=prev;
       prev=curr;
       curr=nxt;
      }
      return prev;
      
      
        
    }
};