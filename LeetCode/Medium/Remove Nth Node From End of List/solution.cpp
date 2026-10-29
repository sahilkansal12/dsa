/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *ptr;
        ListNode* ptr2;
        ptr=head;
        int count=1;
        if(head==NULL) return NULL; 
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            count=count+1;
        }
       if(count==n)
       {

        ListNode* temp=head;
        head=head->next;
        delete temp;
        return head;
       }

       int step=count-n-1;
       ptr2=head;
       int i=0;
       while(i<step)
       {
        ptr2=ptr2->next;
        i++;
       } 
       ListNode* temp=ptr2->next;
       ptr2->next=ptr2->next->next;
        delete temp; 
   return head;

       
    }
};