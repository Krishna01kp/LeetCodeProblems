class Solution {
public:
    vector<vector<int>>res;
    void solve(int n, int k, int idx, vector<int>temp)
    {
        
        if(temp.size()==k) res.push_back(temp);
        else
        for(int i=idx;i<=n;i++)
        {
            temp.push_back(i);
            solve(n,k,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        solve(n,k,1,temp);
        return res;
    }
};