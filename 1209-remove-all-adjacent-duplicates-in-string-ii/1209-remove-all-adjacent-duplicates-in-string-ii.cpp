class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>>st;
        st.push({s[0],1});
        for(int i=1;i<n;i++)
        {
            if(!st.empty() and s[i]==st.top().first)
            {
                st.top().second++;
                if(st.top().second>=k)
                    st.pop();
            }
            else
                st.push({s[i],1});
            
        }
        string ans="";
        while(!st.empty())
        {
            for(int i=0;i<st.top().second;i++)
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};