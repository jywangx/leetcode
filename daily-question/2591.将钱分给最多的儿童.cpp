/*
 * @lc app=leetcode.cn id=2591 lang=cpp
 *
 * [2591] 将钱分给最多的儿童
 */

// @lc code=start
class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children || (children == 1 && money == 4)) return -1;
        if (money-8 < children-1) return 0;
        int n = money/8;
        int m = money%8;
        printf("n=%d, m=%d\n", n, m);
        if (n > children || (n == children && m != 0)) {
            return children - 1;
        } else if (n == children) {
            return children;
        }

        int left_money;
        int left_children;
        if (m + n >= children) {
            left_children = children - n;
            left_money    = m;
        } else {
            int x = (children - n - m + 6) / 7;
            left_children = children - n + x;
            left_money    = m+8*x;
        }
        printf("left_children=%d, left_money=%d\n", left_children, left_money);
        
        if (left_children == 1 && left_money == 4) left_children ++;
        return children - left_children;
    }
};
// @lc code=end

