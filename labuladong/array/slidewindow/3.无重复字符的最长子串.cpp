/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (0 == s.size()) return 0;
        unordered_map<char, int> count;
        int start = 0, end = 1;
        int max_length = 1;
        count[s[0]] ++;
        while (end < s.size()) {
            if (count[s[end]] > 0) {
                while (start < end && count[s[end]] > 0) {
                    count[s[start]] --;
                    start ++;
                }
                count[s[end]] ++;
                end ++;
            } else {
                count[s[end]] ++;
                end ++;
                max_length = max_length >= (end - start) ? max_length : (end - start);
            }
        }
        return max_length;
    }
};
// @lc code=end

