/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int realn = 0;
        for (int i = 0, blankCnt = 0; i < n; i ++) {
            if ((i == 0 && s[i] == ' ') || (i > 0 && s[i] == ' ' && s[i-1] == ' ')) {
                blankCnt ++;
                continue;
            } else if (blankCnt) {
                s[i-blankCnt] = s[i];
            }
            realn ++;
        }
        if (s[realn-1] == ' ') {
            realn --;
        }
        for (int l = 0, r = realn-1; l < r; l ++, r --) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
        }
        for (int l = 0, r = 0; r < realn; ) {
            while (r < realn && s[r] != ' ') {
                r ++;
            }
            for (int il = l, ir = r-1; il < ir; il ++, ir --) {
                char temp = s[il];
                s[il] = s[ir];
                s[ir] = temp;
            }
            r ++;
            l = r;
        }
        return s[0] == ' ' ? s.substr(1, realn) : s.substr(0, realn);
    }
};
// @lc code=end

