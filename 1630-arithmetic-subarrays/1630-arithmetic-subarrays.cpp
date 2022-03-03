class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size(),m=l.size();
        vector<bool>ans(m,0);
        for(int i=0;i<m;i++)
        {
            int x=l[i],y=r[i];
            if(y-x<1)continue;
            vector<int>temp;
            for(int k=x;k<=y;k++)
            {
                temp.push_back(nums[k]);
            }
            sort(temp.begin(),temp.end());
            
            int d=temp[1]-temp[0];
            bool flag=1;
            for(int j=1;j<temp.size()-1;j++)
            {
                if(temp[j+1]-temp[j]!=d)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)ans[i]=1;
        }
        return ans;
    }
};