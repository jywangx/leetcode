/*
 * @lc app=leetcode.cn id=2103 lang=cpp
 *
 * [2103] 环和杆
 */

// @lc code=start
class Solution {
public:
    int countPoints(string rings) {
        int r = 1, g = 2, b = 4;
        int color;
        int rods[10] = {0};
        int res = 0;
        for (char &c: rings) {
            if (c == 'R') {
                color = r;
            } else if (c == 'G') {
                color = g;
            } else if (c == 'B') {
                color = b;
            } else {
                int ring = c - '0';
                rods[ring] |= color;
            }
        }
        for (int &rod: rods) {
            if (rod == 7) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end