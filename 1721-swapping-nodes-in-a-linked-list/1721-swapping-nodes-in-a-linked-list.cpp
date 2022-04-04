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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode *p=head,*q=head,*temp=head;
        while(--k)
            p=p->next;
        temp=p;
        p=p->next;
        while(p)
        {
            p=p->next;
            q=q->next;
        }
        swap(temp->val,q->val);
            return head;
        
        
    }
};