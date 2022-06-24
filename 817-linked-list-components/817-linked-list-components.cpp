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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode*p=head;
        int ans=0;
        while(p)
        {
            if(st.count(p->val) and (p->next==NULL or !st.count(p->next->val)))ans++;
            p=p->next;
        }
        return ans;
    }
};