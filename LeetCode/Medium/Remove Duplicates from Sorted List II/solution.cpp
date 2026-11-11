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
    ListNode* deleteDuplicates(ListNode* head) {
        // set<int> s;
        unordered_map<int, int> mp;
        ListNode* ptr = head;
        while (ptr != NULL) {
            mp[ptr->val]++;
            ptr = ptr->next;
        }

        ListNode* head1 = NULL;
        ListNode* tail = NULL;
         ptr=head;
        while(ptr!=NULL) {
            if (mp[ptr->val]==1) {
                ListNode* NewNode = new ListNode(ptr->val);
                if (head1 == NULL) {
                    head1 = NewNode;
                    tail = NewNode;
                } else {
                    tail->next = NewNode;
                    tail = NewNode;
                }
            }
            ptr=ptr->next;
        }
        return head1;
    }
};