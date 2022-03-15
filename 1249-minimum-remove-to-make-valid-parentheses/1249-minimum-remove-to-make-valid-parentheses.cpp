class Solution {
public:
   string minRemoveToMakeValid(string s) {
        stack<int> box;
        int n = s.length();
        
        for(int i=0; i<n; i++) {
            if(s[i] == ')'){
                if(!box.empty() && s[box.top()] == '('){
                    box.pop();
                }else{
                    s.erase(i,1);
                    i--;
                }
            }
            else if(s[i] == '('){
                box.push(i);
            }
        }
        
        while(!box.empty()) {
            s.erase(box.top(),1);
            box.pop();
        }
        
        return s;
    }
};