class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      stack<int>st;
        for(int i=0,j=0;i<pushed.size()&& j<popped.size();i++)
        {
            st.push(pushed[i]);
            // if(st.top()==popped[j])
            // {
            //     st.pop();
            //     j++;
                while(!st.empty() && st.top()==popped[j])
                {
                    st.pop();
                     j++;
                }
           // }
        }
        return st.empty();
    }
};