/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n+1-k);
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k-1; i ++) {
            pq.push({nums[i], i});
        }
        for (int i = 0; i < n+1-k; i ++) {
            pq.push({nums[i+k-1], i+k-1});
            for (; !pq.empty() && pq.top().second < i; pq.pop());
            res[i] = pq.top().first;
        }
        return res;
    }
};
// @lc code=end

