class Solution {
public:
    void rev(vector<char> &s,int left,int right)
    {
        if(left>=right)
            return;
        swap(s[left++],s[right--]);
        rev(s,left,right);
    }
    void reverseString(vector<char>& s) {
        int n=s.size();
        rev(s,0,n-1);
    }
};