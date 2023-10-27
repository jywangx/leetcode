/*
 * @lc app=leetcode.cn id=1465 lang=cpp
 *
 * [1465] 切割后面积最大的蛋糕
 */

// @lc code=start
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int last = 0;
        int max_h = 0, max_v = 0;
        for (int &num: horizontalCuts) {
            max_h = max(max_h, num - last);
            // printf("last %d, num %d, max_h %d\n", last, num, max_h);
            last = num;
        }
        max_h = max(max_h, h - last);
        // printf("last %d, num %d, max_h %d\n", last, h, max_h);

        last = 0;
        for (int &num: verticalCuts) {
            max_v = max(max_v, num - last);
            // printf("last %d, num %d, max_v %d\n", last, num, max_v);
            last = num;
        }
        max_v = max(max_v, w - last);
        // printf("last %d, num %d, max_h %d\n", last, w, max_v);

        return ((long long)max_h * (long long)max_v) % 1000000007;
    }
};
// @lc code=end

