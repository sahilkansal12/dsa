# Remove Duplicates from Sorted List II

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | November 11, 2026 |
| **Tags** | Linked List, Two Pointers |
| **Link** | [View Problem](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) |
| **Runtime** | 4 ms |
| **Memory** | 16.3 MB |

## Problem Description

<p>You are given the <code>head</code> of a <strong>sorted</strong> linked list.</p>

<p>Delete all nodes that have <strong>duplicate</strong> numbers, leaving only <strong>distinct</strong> numbers from the original list.</p>

<p>Return the linked list <strong>sorted</strong> as well.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg" style="width: 500px; height: 142px;">
<pre><strong>Input:</strong> head = [1,2,3,3,4,4,5]
<strong>Output:</strong> [1,2,5]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg" style="width: 500px; height: 205px;">
<pre><strong>Input:</strong> head = [1,1,1,2,3]
<strong>Output:</strong> [2,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 300]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li>The list is guaranteed to be <strong>sorted</strong> in ascending order.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: 8 lines C++ solution.faster than 100% submissions|for beginners.explanation of approach
**Author**: [@googly_boy](https://leetcode.com/googly_boy/)
**Upvotes**: 358 👍
**Link**: [View Original Post](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/solutions/1395724/)

---

first make a dummy node and assign its value equals to 0 and its next points to the head of the given linked list.
also make a prev node and point it to the dummy node.
***Always remember that a prev node is always required wherever we have to delete a node or we have to break links and create new links . this thing is very important for beginner coders for developing their intusions in future. That\'s not a rule i have said it on the basis of my coding expirience***.
Then you have to traverse the linked list so run a while loop.
check that if the two adjacent nodes are equal or not if the two adjacent nodes are equal then traverse trhe linked list upto ehen the adjacent nodes are not identical.
Then directly connect the link from prev->next to the head->next.
While in other case is the adjacent nodes are not equal then simply traverse the linked list by prev=prev->next.




 ListNode* deleteDuplicates(ListNode* head) {
       
        ListNode *dummy=new ListNode(0,head);
           ListNode *prev=dummy;
            
            while(head!=NULL){
           
            if(head->next!=NULL && head->val==head->next->val){
                    
    while(head->next!=NULL && head->val==head->next->val)head=head->next;
                         
                       
                            prev->next=head->next;
                    }
                    
                    else prev=prev->next;
                           
                   
                    head=head->next;
            }
            
            return dummy->next;
                
        }
		
		
		//if(you_like_and_understand_my_solution)
		//{
		//  please_upvote++;
		// }
		
		/*Guys plz plz plz upvote my solution if you really like and understand it.and if you stuck at any point then feel free to comment*/.

</details>
