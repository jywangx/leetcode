/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) {
            return {};
        }

        vector<vector<int>> matrix(n, vector<int>(n));
        int i = 1;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                matrix[top][column] = i;
                i ++;
            }
            for (int row = top + 1; row <= bottom; row++) {
                matrix[row][right] = i;
                i ++;
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    matrix[bottom][column] = i;
                    i ++;
                }
                for (int row = bottom; row > top; row--) {
                    matrix[row][left] = i;
                    i ++;
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return matrix;
    }
};
// @lc code=end

