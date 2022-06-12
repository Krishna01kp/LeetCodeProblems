class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& p, long long s) {
        int n=sp.size(), m=p.size();
        sort(p.begin(),p.end());
        vector<int>res(n,0);
        for(int i=0;i<n;i++)
        {
            long long x=(s+sp[i]-1)/sp[i];
            int j=lower_bound(p.begin(),p.end(),x)-p.begin();
            res[i]=(m-j);
        }
        return res;
    }
};