/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size();
        int np = p.size();
        vector<char> sCnt(26, 0);
        vector<char> pCnt(26, 0);
        for (char &c: p) {
            pCnt[c-'a'] ++;
        }
        vector<int> ans;
        int i;
        for (i = 0; i < ns && i < np; i ++) {
            sCnt[s[i]-'a'] ++;
        }
        for (; i < ns; i ++) {
            if (sCnt == pCnt) {
                ans.push_back(i - np);
            }
            sCnt[s[i]-'a'] ++;
            sCnt[s[i-np]-'a'] --;
        }
        if (sCnt == pCnt) {
            ans.push_back(i - np);
        }
        return ans;
    }
};
// @lc code=end

