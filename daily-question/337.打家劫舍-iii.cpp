/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 深度优先搜索TreeNodes
    // 返回一个vector<int>，其中第一个元素表示不偷当前节点的最大值，第二个元素表示偷当前节点的最大值，后序遍历
    vector<int> mydfs(TreeNode* root) {
        // 迭代写法
        vector<int> res = {0, 0};
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode*> st;
        st.push(root);
        unordered_map<TreeNode*, vector<int>> um;
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node->left != nullptr && um.find(node->left) == um.end()) {
                st.push(node->left);
            } else if (node->right != nullptr && um.find(node->right) == um.end()) {
                st.push(node->right);
            } else {
                st.pop();
                vector<int> vl, vr;
                if (node->left != nullptr) {
                    vl = um[node->left];
                } else {
                    vl = vector<int>(2, 0);
                }
                if (node->right != nullptr) {
                    vr = um[node->right];
                } else {
                    vr = vector<int>(2, 0);
                }
                um[node] = {node->val + vl[1] + vr[1], max(vl[0], vl[1]) + max(vr[0], vr[1])};
            }
        }
        return um[root];

    }
    vector<int> dfs(TreeNode* root) {
        vector<int> vl, vr;
        if (root->left != nullptr) {
            vl = dfs(root->left);
        } else {
            vl = vector<int>(2, 0);
        }
        if (root->right != nullptr) {
            vr = dfs(root->right);
        } else {
            vr = vector<int>(2, 0);
        }
        vector<int> res = {
            root->val + vl[1] + vr[1],
            max(vl[0], vl[1]) + max(vr[0], vr[1])
        };
        return res;
    }
    int rob(TreeNode* root) {
        vector<int> res = mydfs(root);
        return max(res[0], res[1]);
    }
};
// @lc code=end

