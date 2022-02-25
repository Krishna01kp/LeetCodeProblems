class Solution {
    
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
 public:
    int countVowelSubstrings(string s) {
        int ans = 0, n = s.size();
        unordered_map<char, int> cnt;
        for (int i = 0; i < n; ++i) {
            cnt.clear();
            for (int j = i; j < n && isVowel(s[j]); ++j) {
                cnt[s[j]]++;
                if (cnt.size() == 5) ++ans;
            }
        }
        return ans;
    }
};