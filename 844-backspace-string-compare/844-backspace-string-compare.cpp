class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s,t;
        for(auto c:S)
        {
            if(c!='#')
            {
                s.push_back(c);
            }
            else if(s.size()!=0)
                s.pop_back();
        }
         for(auto c:T)
        {
            if(c!='#')
            {
                t.push_back(c);
            }
            else if(t.size()!=0)
                t.pop_back();
        }
        return s==t;
    }
};