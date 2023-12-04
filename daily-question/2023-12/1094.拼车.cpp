/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //最小堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (vector<int> &t: trips) {
            minHeap.push({t[1], t[0]});
            minHeap.push({t[2], -t[0]});
        }
        int current = 0;
        while (!minHeap.empty()) {
            current += minHeap.top().second;
            // printf("current time: %d, val: %d, passager: %d\n", minHeap.top().first, minHeap.top().second, current);
            minHeap.pop();
            if (current > capacity) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

