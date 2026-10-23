/* Structure of linked list Node
class Node {
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        unordered_map<int, bool> mp;
                Node* curr=head;
                Node* prev=NULL;

                while(curr!=NULL)
                {
                 if(mp.find(curr->data)!=mp.end())
                 {
                     prev->next=curr->next;
                      curr=curr->next;
                 }
                 else 
                 {
                      mp[curr->data]=true;
                      prev=curr;
                      curr=curr->next;
                 }

                }

                return head;
        
    }
};