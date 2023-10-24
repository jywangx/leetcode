/*
 * @lc app=leetcode.cn id=1654 lang=cpp
 *
 * [1654] 到家的最少跳跃次数
 */

// @lc code=start
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<pair<int, bool>> q;
        q.push({0, true});
        int n = 10000;
        vector<vector<int>> flag(n, vector<int>(2, 0));
        for (int &num: forbidden) {
            flag[num] = {-1, -1};
        }
        if (x == 0 && flag[0][0] != -1) return 0;
        if (x == 0 && flag[0][0] == -1) return -1;
        while (!q.empty()) {
            auto p = q.front();
            int from = p.first;
            bool lastBack = p.second;
            q.pop();
            if (from + a < n && flag[from+a][0] == 0) {
                flag[from+a][0] = flag[from][lastBack ? 1 : 0] + 1;
                if (from+a == x) 
                    return flag[from+a][0];
                q.push({from+a, false});
            }
            if (!lastBack && from - b > 0 && flag[from-b][0] == 0 && flag[from-b][1] == 0) {
                flag[from-b][1] = flag[from][0] + 1;
                if (from-b == x) 
                    return flag[from-b][1];
                q.push({from-b, true});
            }
        }
        return -1;
    }
};
// @lc code=end

