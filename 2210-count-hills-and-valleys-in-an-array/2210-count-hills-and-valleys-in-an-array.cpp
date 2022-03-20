class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size(),cnt=0,pre=nums[0];
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])continue;
            if((pre<nums[i] and nums[i]>nums[i+1]) or (pre>nums[i] and nums[i]<nums[i+1]))
            {
                cnt++;
                pre=nums[i];
            }
        }
        return cnt;
    }
};