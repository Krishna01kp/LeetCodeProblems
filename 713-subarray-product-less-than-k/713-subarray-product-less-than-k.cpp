class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k<=1)return 0;
        int prod=1,ans=0;
        
        for(int i=0,j=0;j<n;j++)
        {
            prod*=nums[j];
            while(i<n and prod>=k)
            {
                prod/=nums[i];
                i++;
            }
            ans+=(j-i+1);
        }
        return ans;
    }
};