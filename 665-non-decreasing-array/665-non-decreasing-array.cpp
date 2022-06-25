class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0,limit=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<limit)
            {
                if(i<2 or nums[i-2]<=nums[i])
                    limit=nums[i];
                if(++cnt==2) return false;
            }
            else
                limit=nums[i];
        }
        return 1;
    }
};