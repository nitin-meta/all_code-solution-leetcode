class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> q;
        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                q.push(-diff);
                if (q.size() > ladders) {
                    bricks += q.top();
                    q.pop();
                }
                if (bricks < 0) {
                    return i;
                }
            }
        }
        return heights.size() - 1;
    }
};
