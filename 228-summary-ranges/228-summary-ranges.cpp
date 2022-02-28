class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)return {};
        int s=nums[0],e=nums[0];
        vector<string>ans;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==e+1)
            {
                e=nums[i];
            }
            else
            {
               string str=to_string(s);
                if(s!=e)
                    str+="->"+to_string(e);
                ans.push_back(str);
                s=nums[i],e=nums[i];
            }
        }
        string str=to_string(s);
                if(s!=e)
                    str+="->"+to_string(e);
                ans.push_back(str);
        return ans;
    }
};