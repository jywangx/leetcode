/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        queue<int> q;
        for (int i = 0; i < nums.size(); i ++) {
            if (s.find(nums[i]) != s.end()) {
                q.push(i);
                continue;
            } else if (!q.empty()) {
                int j = q.front();
                q.pop();
                nums[j] = nums[i];
                q.push(i);
            }
            s.insert(nums[i]);
        }
        return s.size();
    }
};
// @lc code=end

