class Solution {
public:
    int solve(int x, int y)
    {
        return !(y<=(0.5*x +7) or y>x or (y>100 and x<100));
    }
    int numFriendRequests(vector<int>& ages) {
        int n=ages.size();
        int res=0;
        map<int,int>mp;
        for(auto &x:ages)
            mp[x]++;
        for(auto &a:mp)
        {
            for(auto &b:mp)
            {
                if(solve(a.first,b.first))
                    res+=a.second*(b.second - (a.first==b.first?1:0));
            }
        }
        return res;
    }
};