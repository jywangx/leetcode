/*
 * @lc app=leetcode.cn id=2316 lang=cpp
 *
 * [2316] 统计无向图中无法互相到达点对数
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> adjacent;
    vector<int> flags;
    void dfs(int c, int f) {
        if (flags[c]) return;
        flags[c] = f;
        for (int &point: adjacent[c]) {
            dfs(point, f);
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        adjacent = vector<vector<int>>(n);
        flags = vector<int>(n, 0);
        for (auto &edge: edges) {
            adjacent[edge[0]].push_back(edge[1]);
            adjacent[edge[1]].push_back(edge[0]);
        }
        int f = 1;
        for (int i = 0; i < n; i++) {
            if (flags[i] == 0) {
                dfs(i, f);
                f++;
            }
        }
        for (int &flag: flags) {
            cout << flag << " ";
        }
        cout << endl;
        vector<int> cnt(f, 0);
        for (int &flag: flags) {
            if (flag) cnt[flag]++;
        }
        long long res = 0;
        for (int &c: cnt) {
            res += (long long)c * (n - c);
        }
        return res/2;
    }
};
// @lc code=end

