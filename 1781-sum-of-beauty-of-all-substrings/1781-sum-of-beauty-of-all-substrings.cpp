class Solution {
public:
    int beautySum(string s) {
        int n=s.size(),res=0;
        for(int i=0;i<n;i++)
        {
            int minf=0,maxf=0;
            vector<int>fre(26,0);
            for(int j=i;j<n;j++)
            {
                fre[s[j]-'a']++;
                maxf=max(maxf,fre[s[j]-'a']);
                if(minf>=fre[s[j]-'a']-1)
                {
                    minf=fre[s[j]-'a'];
                    for(int k=0;k<26;k++)
                    {
                     minf=min(minf,(fre[k]==0?INT_MAX:fre[k]));
                    }
                }
                
                res+=(maxf-minf);
            }
        }
        return res;
    }
};