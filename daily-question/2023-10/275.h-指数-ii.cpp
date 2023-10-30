/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n;
        for (int mid = (right + left)/2; left < right; mid = (right + left)/2) {
            if (citations[mid] >= n-mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        } 
        return n - right;
    }
};
// @lc code=end

