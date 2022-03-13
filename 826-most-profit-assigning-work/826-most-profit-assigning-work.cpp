class Solution {
public:
    int maxProfitAssignment(vector<int>& dif, vector<int>& p, vector<int>& w) {
        int n=w.size(),m=dif.size();
        int ans=0,i=0,curr=0;
        vector<pair<int,int>>temp;
        for(int i=0;i<m;i++)
        {
            temp.push_back({dif[i],p[i]});
        }
        sort(temp.begin(),temp.end());
        sort(w.begin(),w.end());
        for(auto x:w)
        {
            while(i<m and x>=temp[i].first)
            {
                curr=max(curr,temp[i++].second);
            }
            ans+=curr;
        }
        return ans;
    }
};