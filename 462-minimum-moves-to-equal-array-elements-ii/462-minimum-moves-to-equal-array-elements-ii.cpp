class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int t= nums[n/2];
        int ans=0;
        for(auto n:nums)
        {
            ans+=abs(n-t);
        }
        return ans;
    }
};