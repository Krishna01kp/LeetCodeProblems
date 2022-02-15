class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
        int n=times.size();
        int target=times[t][0];
    
        sort(times.begin(),times.end());
        //meanheap for available chair
        priority_queue<int,vector<int>,greater<int>>pq_chair;
        for(int i=0;i<n;i++)
        {
            pq_chair.push(i);
        }
        //meanheap for when leaving and chair number
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq_leave;
        
        for(auto m:times)
        {
            int at=m[0];
            int dt=m[1];
            while(!pq_leave.empty() and pq_leave.top().first<=at)
            {
                auto p=pq_leave.top();
                pq_leave.pop();
                pq_chair.push(p.second);
            }
            int chair=pq_chair.top();
            pq_chair.pop();
            pq_leave.push({dt,chair});
            if(at==target)return chair; 
        }
        return 0;
    }
};