class Solution {
public:
    int minBitFlips(int start, int goal) {
         int cnt = 0;
            for (int i = 32; i >= 0; i--)
            {
                
				cnt += (((1LL << i) & start)!=((1LL << i) & goal));
            }
            return cnt;
    }
};