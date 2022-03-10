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
typedef ListNode* lptr;
class Solution {
public:
lptr add(lptr l1, lptr l2, int carry=0)
{
 if(!l1 and !l2)
 {
   if(carry) return new ListNode(carry);
   return NULL;
 }
 int a=l1?l1->val:0;
 int b=l2?l2->val:0;
 int sum=(a+b+carry);
 lptr cur=new ListNode(sum%10);
 cur->next=add(l1?l1->next:l1 , l2?l2->next:l2 ,sum/10); //if l1 is null we cant access l1->next 
        return cur;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1,l2);
    }
};