//Good Question: revise it again
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1; // No solution possible noob
        int n = nums.size();
        int ps = 0, res = INT_MAX;
        for (int i = 0, j = 0; j < n; j++) {
            ps += nums[j];
            while (ps > target && i <= j) {
                ps -= nums[i];
                i++;
            }
            if (ps == target) {
                res = min(res, n - (j - i + 1));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

