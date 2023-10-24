/*
 * @lc app=leetcode.cn id=1726 lang=cpp
 *
 * [1726] 同积元组
 */

// @lc code=start
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> map;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                int temp = nums[i] * nums[j];
                if (map.find(temp) != map.end()) {
                    ans += map[temp];
                }
                map[temp]++;
            }
        }
        return ans * 8;
    }
};
// @lc code=end

