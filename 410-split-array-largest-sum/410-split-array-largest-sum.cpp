class Solution {
public:
    int solve(int max, vector<int>&nums,int m)
    {
        int curr=0;
        for(auto n:nums)
        {
            if(curr+n>max)
            {
                m--;
                curr=n;
                if(m<=0)return 0;
            }
            else
            {
                curr+=n;
            }
        }
        return 1;
    }
    int splitArray(vector<int>& nums, int m) {
        int left,right;
        left=*max_element(nums.begin(),nums.end());
        right=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(solve(mid,nums,m))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};