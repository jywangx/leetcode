/*
 * @lc app=leetcode.cn id=2003 lang=cpp
 *
 * [2003] 每棵子树内缺失的最小基因值
 */

// @lc code=start
class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int> &parents, vector<int> &nums) {
        int n = parents.size();
        vector<int> ans(n, 1);
        auto it = find(nums.begin(), nums.end(), 1);
        if (it == nums.end()) { // 不存在基因值为 1 的点
            return ans;
        }

        // 建树
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[parents[i]].push_back(i);
        }

        unordered_set<int> vis;
        stack<int> nodes; // 保存接下来需要遍历的点
        int mex = 2; // 缺失的最小基因值
        int pre = -1;
        int node = it - nums.begin();
        while (node >= 0) {
            vis.insert(nums[node]); // 标记基因值
            for (int son: g[node]) {
                if (son != pre) { // pre 子树已经遍历过了
                    nodes.push(son); // 保存接下来需要遍历的点
                }
            }
            while (!nodes.empty()) {
                int x = nodes.top();
                nodes.pop();
                vis.insert(nums[x]); // 标记基因值
                for (int son: g[x]) {
                    nodes.push(son); // 保存接下来需要遍历的点
                }
            }
            while (vis.count(mex)) { // node 子树包含这个基因值
                mex++;
            }
            ans[node] = mex; // 缺失的最小基因值
            pre = node; // 下一轮循环不会遍历 pre 子树
            node = parents[node]; // 往上走
        }
        return ans;
    }
};
// @lc code=end

