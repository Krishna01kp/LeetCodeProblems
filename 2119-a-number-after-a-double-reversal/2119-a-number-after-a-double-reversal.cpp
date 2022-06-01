class Solution {
public:
    bool isSameAfterReversals(int num) {
        string s=to_string(num);
        string temp=s;
        reverse(s.begin(),s.end());
        
        int i=0;
        while(i<s.size()-1 and s[i]=='0')
            i++;
        string rev1=s.substr(i,s.size()-i);
        reverse(rev1.begin(),rev1.end());
        i=0;
        while(i<rev1.size()-1 and rev1[i]=='0')
            i++;
        string rev2=rev1.substr(i,rev1.size()-i);
        
        return rev2==temp;
    }
};