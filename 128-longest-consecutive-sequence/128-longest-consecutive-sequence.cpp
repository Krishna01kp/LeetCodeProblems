class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_set<int> seen(nums.begin(),nums.end());
        for(auto n:nums)
        {
            if(seen.find(n)==seen.end())continue;
            seen.erase(n);
            int prev=n-1, nxt=n+1;
            while(seen.count(prev))seen.erase(prev--);
            while(seen.count(nxt))seen.erase(nxt++);
            ans=max(ans,nxt-prev-1);
        }
        return ans;
    }
};