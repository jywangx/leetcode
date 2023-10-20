/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<char> s1Cnt(26, 0);
        vector<char> s2Cnt(26, 0);
        for (char &c: s1) {
            s1Cnt[c-'a'] ++;
        }
        int i;
        for (i = 0; i < n1 && i < n2; i ++) {
            s2Cnt[s2[i]-'a'] ++;
        }
        for (; i < n2; i ++) {
            if (s2Cnt == s1Cnt) {
                return true;
            }
            s2Cnt[s2[i]-'a'] ++;
            s2Cnt[s2[i-n1]-'a'] --;
        }
        if (s2Cnt == s1Cnt) {
            return true;
        }
        return false;
    }
};
// @lc code=end

