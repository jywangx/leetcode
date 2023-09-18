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
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
};
// @lc code=end

