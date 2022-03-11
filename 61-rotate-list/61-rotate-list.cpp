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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode *p=head,*q=head;
        int len=1;
        while(p->next)
        {
            p=p->next;
            len++;
        }
        k%=len;
        p->next=head;
        for(int i=1;i<len-k;i++)
        {
            q=q->next;
        }
        head=q->next;
        q->next=NULL;
        return head;
    }
};