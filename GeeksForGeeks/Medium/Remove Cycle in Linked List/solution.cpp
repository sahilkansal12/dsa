/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
  
    Node* detect(Node* head)
    {
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {return slow;
              break;
            }
            
        }
        return NULL;
    }
    void removeLoop(Node* head) {
        Node* meet=detect(head);
        
        if(meet==NULL)
         return;
        
        Node* del=meet;
       
        Node* start=head;
        if(meet==head)
        {
            while(del->next!=start)
            {
                del=del->next;
            }
        }  
       
        else{
        
        while(start->next!=meet->next)
        {
            meet=meet->next;
            start=start->next;
            del=del->next;
        }
        }
        del->next=NULL;
        
    }
};