/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
private:
    vector<vector<int>> prefix_sum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix_sum = vector<vector<int>>(
            matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0)
        );
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j ++) {
                prefix_sum[i + 1][j + 1] = prefix_sum[i + 1][j] 
                                           + prefix_sum[i][j + 1] 
                                           - prefix_sum[i][j] 
                                           + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (
            prefix_sum[row2 + 1][col2 + 1] 
            - prefix_sum[row2 + 1][col1] 
            - prefix_sum[row1][col2 + 1] 
            + prefix_sum[row1][col1]
        );
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

