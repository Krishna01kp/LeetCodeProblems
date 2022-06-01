class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num==0)return true;
        //convert number to string 
        string s=to_string(num);
        string temp=s; // keep a copy to check in last
        reverse(s.begin(),s.end());
        
        int i=0;
        while(i<s.size() and s[i]=='0') // remove all the leading zeroes
            i++;
        string rev1=s.substr(i,s.size()-i); // new string after first reverse
        reverse(rev1.begin(),rev1.end());
        i=0;
        while(i<rev1.size()-1 and rev1[i]=='0')
            i++;
        string rev2=rev1.substr(i,rev1.size()-i);
        
        return rev2==temp; // check if initial string and string after 2 reversal are equal
    }
};