class Solution {
public:
    int dp[370];
    int solve(int i,vector<int>& days, vector<int>& costs)
    {
        if(i==days.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int one=costs[0]+solve(i+1,days,costs);
        int idx=lower_bound(days.begin()+i,days.end(),days[i]+7)-days.begin();
        int two=costs[1]+solve(idx,days,costs);
        idx=lower_bound(days.begin()+i,days.end(),days[i]+30)-days.begin();
        int three=costs[2]+solve(idx,days,costs);
        return dp[i]=min({one,two,three});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0,days,costs);
    }
};