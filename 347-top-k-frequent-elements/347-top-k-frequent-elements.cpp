class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         vector<int> ans;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
	for (auto f : m)
		pq.push( { f.second, f.first } );

	while (k-- > 0) {
		ans.push_back(pq.top().second);
		pq.pop();
	}
	return ans;
    }
};