class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i=n-1;
        while(i>=0 and digits[i]==9)
        {
            digits[i]=0;
            i--;
        }
        if(i>=0)
            digits[i]++;
        else if(i==-1)
        {
            digits.resize(n+1,0);
            digits[0]=1;
        }
        return digits;
    }
};