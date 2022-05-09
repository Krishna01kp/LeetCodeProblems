class Solution {
public:
    vector<string>res={};
    int n;
    void solve(string &digits, vector<string>&nums, int indx,string op)
    {
        //base case
        if(indx==n)
        {
            res.push_back(op);
            return;
        }
        //recursion
        string temp=nums[digits[indx]-'0'];
        for(int i=0;i<temp.size();i++)
        {
            solve(digits,nums,indx+1,op+temp[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        n=digits.size();
        if(n==0)
            return res;
        vector<string>nums={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,nums,0,"");
        return res;
    }
};