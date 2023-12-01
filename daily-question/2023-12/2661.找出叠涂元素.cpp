/*
 * @lc app=leetcode.cn id=2661 lang=cpp
 *
 * [2661] 找出叠涂元素
 */

// @lc code=start
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<int> rowCnt(n, 0);
        vector<int> colCnt(m, 0);
        unordered_map<int, pair<int, int>> arr2Pos;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                arr2Pos[mat[i][j]] = make_pair(i, j);
            }
        }

        for (int i = 0; i < n*m; i ++) {
            int x = arr2Pos[arr[i]].first;// n
            int y = arr2Pos[arr[i]].second;// m
            rowCnt[y]++;
            colCnt[x]++;
            if (colCnt[x] == n || rowCnt[y] == m) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

