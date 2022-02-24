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
    ListNode* merge(ListNode *h1, ListNode *h2)
    {
        if(!h1) return h2;
        if(!h2) return h1;
        if(h1->val< h2->val)
        {
            h1->next = merge(h1->next, h2);
            return h1;
        }
        else
        {
            h2->next = merge(h1,h2->next);
            return h2;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode *p=head, *q=head;
        while(q->next and q->next->next)
        {
            p=p->next;
            q=q->next->next;
        }
        ListNode* Next=p->next;
        p->next=NULL;
        ListNode *h1=sortList(head);
        ListNode *h2=sortList(Next);
        return merge(h1,h2);
    }
};