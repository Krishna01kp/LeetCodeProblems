class Solution {
public:
    int findFinalValue(vector<int>& nums, int x) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==x)
            {
                x*=2;
            }
        }
        return x;
    }
};