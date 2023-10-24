/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};
        int mid, l = 0, r = 0;
        int resL, resR;
        for (l = 0, r = nums.size() - 1; l <= r; ) {
            mid = l + (r-l)/2;
            if (nums[mid] == target) break;
            else if (nums[mid] < target) l = mid + 1;
            else if (nums[mid] > target) r = mid - 1;
        }
        if (nums[mid] != target) return {-1, -1};
        for (l = 0, r = nums.size(); l < r; ) {
            mid = l + (r-l)/2;
            if (nums[mid] == target) r = mid;
            else if (nums[mid] < target) l = mid+1;
            else if (nums[mid] > target) r = mid;
        }
        resL = l;
        for (l = 0, r = nums.size(); l < r; ) {
            mid = l + (r-l)/2;
            if (nums[mid] == target) l = mid+1;
            else if (nums[mid] < target) l = mid+1;
            else if (nums[mid] > target) r = mid;
        }
        resR = l - 1;
        return {resL, resR};
    }
};
// @lc code=end

