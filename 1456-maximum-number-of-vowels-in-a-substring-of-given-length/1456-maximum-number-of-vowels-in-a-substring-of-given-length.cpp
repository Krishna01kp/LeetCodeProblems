class Solution {
public:
    string v="aeiou";
    int isVowel(char c)
    {
        for(auto x:v)
        {
            if(x==c)return 1;
        }
        return 0;
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        vector<int>prefix(n,0);
        prefix[0]=isVowel(s[0]);
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+isVowel(s[i]);
        }
        int res=0;
        for(int i=0;i<n-k+1;i++)
        {
            res=max(res,prefix[i+k-1]-prefix[i]+isVowel(s[i]));
        }
        return res;
    }
};