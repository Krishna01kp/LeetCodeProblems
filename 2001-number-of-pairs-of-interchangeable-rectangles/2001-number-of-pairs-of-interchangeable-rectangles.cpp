class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rec) {
        int n=rec.size();
        long long res=0;
        unordered_map<double,int>mp;
        for(auto x:rec)
        {
            res=res+mp[(double)x[0]/(double)x[1]]++;
        }
        return res;
    }
};