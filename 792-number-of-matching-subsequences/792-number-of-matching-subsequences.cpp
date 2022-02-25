class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt=0,k=s.size(),n=words.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[words[i]]++;
        }
        for(auto x:mp)
        {
            int i=0,j=0;
            string p=x.first;
            int m=p.size();
            while(i<k && j<m)
            {
                if(s[i]==p[j])
                {
                    i++;
                    j++;
                }
                else
                    i++;
            }
            if(j==m)
                cnt+=x.second;
        }
        return cnt;
    }
};