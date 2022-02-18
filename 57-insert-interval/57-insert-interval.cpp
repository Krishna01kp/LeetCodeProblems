class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<=0)
            return {};
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int s=intervals[0][0],e=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=e)
            {
                e=max(e,intervals[i][1]);
            }
            else
            {
                ans.push_back({s,e});
                s=intervals[i][0];
                e=intervals[i][1];
            }
        }
        ans.push_back({s,e});
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intv, vector<int>& newIn) {
        // int n=intv.size();
        // if(n==0)return {newIn};
        // int lo=0,hi=n-1,mid,idx;
        // while(lo<hi)
        // {
        //     mid=(lo+hi)/2;
        //     if(intv[mid][0]<=newIn[0])
        //     {
        //         idx=mid;
        //         lo++;
        //     }
        //     else
        //         hi--;
        // }
        intv.push_back(newIn);
        return merge(intv);
        
    }
};