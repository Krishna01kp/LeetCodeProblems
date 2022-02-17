class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>& cad,vector<int>temp, int t,int idx)
    {
        if(t==0)
        {
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<cad.size() and cad[i]<=t;i++)
        {
            temp.push_back(cad[i]);
            solve(cad,temp,t-cad[i],i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cad, int t) {
        sort(cad.begin(),cad.end());
        vector<int>temp;
        solve(cad,temp,t,0);
        return res;
    }
};