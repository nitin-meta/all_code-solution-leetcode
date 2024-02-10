class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int len = 0;
        
        for (int num : st) {
            if (!st.count(num - 1)) {
                int currentNum = num;
                int cur = 1;
                
                while (st.count(currentNum + 1)) {
                    currentNum++;
                    cur++;
                }
                
                len = max(len, cur);
            }
        }
        
        return len;
    }
};
