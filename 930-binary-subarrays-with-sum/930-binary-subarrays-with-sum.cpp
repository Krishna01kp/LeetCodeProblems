class Solution {
public:
    int atmost_k(vector<int>&nums, int k)
    {
        if(k<0)return 0;
        int n=nums.size();
        int ans=0,sum=0;
        for(int i=0,j=0;j<n;j++)
        {
            sum+=nums[j];
            while(i<n and sum>k)
            {
                
                sum-=nums[i++];
            }
            ans+=(j-i+1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost_k(nums,goal)-atmost_k(nums,goal-1);
    }
};