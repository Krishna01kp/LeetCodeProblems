class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>minr(n),maxl(n);
        minr[n-1]=nums[n-1],maxl[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            maxl[i]=max(nums[i],maxl[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            minr[i]=min(nums[i],minr[i+1]);
        }
        int i=0,j=n-1;
        while(i<n and nums[i]<=minr[i])i++;
        while(j>i and nums[j]>=maxl[j])j--;
        return j-i+1;
    }
};