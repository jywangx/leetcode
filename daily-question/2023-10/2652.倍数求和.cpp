/*
 * @lc app=leetcode.cn id=2652 lang=cpp
 *
 * [2652] 倍数求和
 */

// @lc code=start
class Solution {
public:
    int sumOfMultiples(int n) {
        
        int x = (n / 3) * 3;
        int res = (3+x) * (x/3) / 2;

        x = (n/5) * 5;
        res += (5+x) * (x/5) / 2;

        x = (n/7) * 7;
        res += (7+x) * (x/7) / 2;

        x = (n / 35) * 35;
        res -= (35+x) * (x/35) / 2;

        x = (n/15) * 15;
        res -= (15+x) * (x/15) / 2;

        x = (n/21) * 21;
        res -= (21+x) * (x/21) / 2;

        x = (n/105) * 105;
        res += (105+x) * (x/105) / 2;

        return res;
    }
};
// @lc code=end

