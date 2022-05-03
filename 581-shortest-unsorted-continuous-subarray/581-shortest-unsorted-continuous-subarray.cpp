class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int j=-1,k=-1,max=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(max>nums[i])
            {
                if(j==-1)j=i-1;
                while(j-1 >=0 and nums[j-1]>nums[i])j--;
                k=i+1;
            }
            else
            max=nums[i];
        }
        return k-j;
    }
};