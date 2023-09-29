/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        queue<int> q;
        int len = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == val) {
                q.push(i);
                continue;
            } else if (!q.empty()) {
                int j = q.front();
                q.pop();
                nums[j] = nums[i];
                q.push(i);
            }
            len ++;
        }
        return len;
    }
};
// @lc code=end

