class Solution {
public:
    int solve(vector<int>&q,long long int k)
    {
        int hr=0;
        for(auto a:q)
        {
           hr+=(a+k-1)/k; 
        }
        return hr;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        long long int lo=1,hi=1e11,mid,ans;
        while(lo<=hi)
        {
            mid=hi -(hi-lo)/2;
            if(solve(q,mid)>n)
                lo=mid+1;
            else 
            {
                hi=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};