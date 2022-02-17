class Solution {
public:
    vector<vector<int>>res;
    void solve(int idx, int k, int n, vector<int>temp)
    {
        if(n<0)return;
        if(temp.size()==k and n==0)
        {
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<=9;i++)
        {
            temp.push_back(i);
            solve(i+1,k,n-i,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(1,k,n,temp);
        return res;
    }
};