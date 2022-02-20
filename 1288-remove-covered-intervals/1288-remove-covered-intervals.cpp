class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        int n=inter.size(),cnt=1;
        sort(inter.begin(),inter.end());
        int start=inter[0][0],end=inter[0][1];
        for(int i=1;i<n;i++)
        {
            if(inter[i][0]>start and end<inter[i][1])
            {
                cnt++;
            }
            if(end<inter[i][1])
            {
                start=inter[i][0],end=inter[i][1];
            }
        }
        return cnt;
    }
};