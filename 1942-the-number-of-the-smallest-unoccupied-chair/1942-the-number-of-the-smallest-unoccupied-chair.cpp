class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
        int n=times.size();
        vector<pair<int,pair<int,int>>>mp;
        for(int i=0;i<n;i++)
        {
            int at=times[i][0];
            int dt=times[i][1];
            mp.push_back({at,{dt,i}});
        }
        sort(mp.begin(),mp.end());
        vector<int>rec(n,-1);
        for(auto m:mp)
        {
            int at=m.first;
            int dt=m.second.first;
            int idx=m.second.second;
            for(int i=0;i<n;i++)
            {
                if(rec[i]<=at)
                {
                    rec[i]=dt;
                    if(idx==t)return i;
                    break;
                }
            }
        }
        return 0;
    }
};