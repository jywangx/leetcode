/*
 * @lc app=leetcode.cn id=2525 lang=cpp
 *
 * [2525] 根据规则将箱子分类
 */

// @lc code=start
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool isBulky = (length >= 1e4 || width >= 1e4 || height >= 1e4 || (long long)length*width*height >= 1e9);
        bool isHeavy = mass >= 100;
        if (isBulky && isHeavy) return "Both";
        else if (isBulky) return "Bulky";
        else if (isHeavy) return "Heavy";
        else return "Neither";
    }
};
// @lc code=end

