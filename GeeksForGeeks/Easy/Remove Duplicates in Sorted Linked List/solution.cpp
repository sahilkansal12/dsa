/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        Node* curr=head;
            if (head==NULL) return NULL;

           while(curr!=NULL&&curr->next!=NULL){    
            if (curr->data==curr->next->data)
            {
                 curr->next=curr->next->next;
            }
            else
             curr=curr->next;
           }
                return head;
            
        
    }
};