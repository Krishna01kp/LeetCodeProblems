class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n=ops.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(ops[i]=="+")
            {
                int temp=st.top();
                st.pop();
                int x=temp+st.top();
                st.push(temp);
                st.push(x);
            }
            else if(ops[i]=="D")
            {
                st.push(2*st.top());
            }
            else if(ops[i]=="C")
            {
                st.pop();
            }
            else
                st.push(stoi(ops[i]));
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};