class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        string ans="";
        st.push(num[0]);
        for(int i=1;i<n;i++)
        {
            while(!st.empty() and k and num[i]<st.top())
            {
                st.pop();
                k--;
            }
            if(!st.empty() or num[i]!='0') 
             st.push(num[i]);
        }
        while(!st.empty() and k--)
            st.pop();
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        if(ans.empty())
            return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};