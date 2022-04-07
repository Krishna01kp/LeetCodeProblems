class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n=stones.size();
        int x,y;
        for(int i=0;i<n;i++)
            pq.push(stones[i]);
        while(!pq.empty())
        {
            x=pq.top();
            pq.pop();
            if(pq.empty())
             return x;
            y=pq.top();
            x=abs(x-y);
            pq.pop();
            if(x)
            {
                pq.push(x);
            }
        }
        return 0;
    }
};