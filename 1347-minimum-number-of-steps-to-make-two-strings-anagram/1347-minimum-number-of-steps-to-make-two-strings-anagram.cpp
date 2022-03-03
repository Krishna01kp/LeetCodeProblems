class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.size();
        unordered_map<char,int>mp1,mp2;
        for(auto c:s)
            mp2[c]++;
        for(auto c:t)
            mp1[c]++;
        int ans=0;
        for(auto c:s)
        {
            if(mp1[c]<mp2[c])
            ans+=(mp2[c]-mp1[c]);
            mp1[c]=mp2[c];
        }
        return ans;
    }
};