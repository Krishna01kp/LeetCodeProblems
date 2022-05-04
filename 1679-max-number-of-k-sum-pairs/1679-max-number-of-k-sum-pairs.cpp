class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
                if(mp[k-nums[i]])
                {
                    count++;
                    mp[k-nums[i]]--;
                }
            else
            mp[nums[i]]++;
        }
        return count;
    }
};