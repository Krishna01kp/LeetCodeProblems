class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            int d=nums[i+1]-nums[i];
            //int cnt=0;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]-nums[j-1]==d)
                {
                    if(j-i>=2)ans++;
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};