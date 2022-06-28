class Solution {
public:
    int minDeletions(string s) {
        int ans=0;
        vector<int>fre(26,0);
        for(auto c:s)
        {
            fre[c-'a']++;
        }
        sort(fre.rbegin(),fre.rend());
        int mxf=fre[0];
        for(auto x:fre)
        {
            if(x>mxf)
            {
                if(mxf>0)
                {
                    ans+=(x-mxf);
                }
                else
                {
                   ans+=x; 
                }
            }
            mxf=min(mxf-1,x-1);
        }
        
        return ans;
    }
};