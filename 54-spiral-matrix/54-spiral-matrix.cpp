class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mt) {
        int n=mt.size(), m=mt[0].size();
        vector<int>res;
        int t=0,b=n-1,l=0,r=m-1,d=0;
        while(l<=r and t<=b)
        {
            if(d==0)
            {
                for(int i=l;i<=r;i++)
                {
                    res.push_back(mt[t][i]);
                }
                t++;
            }
            else if(d==1)
            {
                for(int i=t;i<=b;i++)
                {
                    res.push_back(mt[i][r]);
                }
                r--;
            }
            else if(d==2)
            {
                for(int i=r;i>=l;i--)
                {
                    res.push_back(mt[b][i]);
                }
                b--;
            }
            else
            {
                for(int i=b;i>=t;i--)
                {
                    res.push_back(mt[i][l]);
                }
                l++;
            }
            d=(d+1)%4;
        }
        return res;
    }
};