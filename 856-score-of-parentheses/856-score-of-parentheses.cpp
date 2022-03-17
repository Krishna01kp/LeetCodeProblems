class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans=0;
        stack<int>st;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='(')
                st.push(-1);
            else
            {
                if(st.top()==-1)
                {
                    st.pop();
                    st.push(1);
                }
                else
                {
                    int x=0;
                    while(st.top()!=-1)
                    {
                        x+=st.top();
                        st.pop();
                    }
                    x*=2;
                    st.pop();
                    st.push(x);
                }
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};