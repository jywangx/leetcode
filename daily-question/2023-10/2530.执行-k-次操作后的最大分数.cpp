/*
 * @lc app=leetcode.cn id=2530 lang=cpp
 *
 * [2530] 执行 K 次操作后的最大分数
 */

// @lc code=start
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; i ++) {
            pq.push(nums[i]);
        }
        for (int i = 0; i < k; i ++) {
            int x = pq.top();
            pq.pop();
            pq.push((x+2)/3);
            res += x;
        }
        return res;
    }
};
// @lc code=end

