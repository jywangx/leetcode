/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
private:
    vector<int> prefix_sum;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix_sum.resize(n + 1, 0);
        for (int i = 0; i < n; i ++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix_sum[right + 1] - prefix_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

