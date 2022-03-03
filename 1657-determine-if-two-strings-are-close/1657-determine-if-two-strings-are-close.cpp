class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        if(n!=m)return false;
        vector<int>fre1(26,0),fre2(26,0);
        unordered_set<char>s1,s2;
        for(auto w:word1)
        {
            fre1[w-'a']++;
            s1.insert(w);
        }
        for(auto w:word2)
        {
            fre2[w-'a']++;
            s2.insert(w);
        }
        
        sort(fre1.begin(),fre1.end());
        sort(fre2.begin(),fre2.end());
        
        return (s1==s2 and fre1==fre2);
    }
};