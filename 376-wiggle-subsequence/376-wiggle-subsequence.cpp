class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>temp;
        int n=nums.size();
        if(n<2)return 1;
        // for(int i=1;i<n;i++)
        // {
        //     temp.push_back(nums[i]-nums[i-1]);
        // }
        int g=1,s=1,f=1;
        // if(temp[0]<0)f=0;
        // if(temp.size()<3)return 2;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
                g=s+1;
            else if(nums[i]<nums[i-1])
                s=g+1;
//             if(f)
//             {
//                 if(temp[i]<0)
//                 {
//                     s++;
//                     f=0;
//                 }
//             }
//             else
//             {
//                 if(temp[i]>=0)
//                 {
//                     s++;
//                     f=1;
//                 }
    
//             }
        }
        return max(g,s);
    }
};