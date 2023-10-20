/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int j = 0; j < n; j ++) {
            for (int il = 0, ir = n-1; il < ir; il ++, ir --) {
                int temp = matrix[j][il];
                matrix[j][il] = matrix[j][ir];
                matrix[j][ir] = temp;
            }
        }
    }
};
// @lc code=end

