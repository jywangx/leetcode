/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> stk;
        int times = 0;
        string res = "";
        for (char &c: s) {
            if (c >= '0' && c <= '9') {
                times = times*10 + c-'0';
            } else if (c >= 'a' && c <= 'z') {
                res += c;
            } else if (c == '[') {
                stk.push({res, times});
                res = "";
                times = 0;
            } else if (c == ']') {
                auto p = stk.top();
                string tempStr = "";
                stk.pop();
                for (int i = 0; i < p.second; i ++) {
                    tempStr += res;
                }
                res = p.first + tempStr;
            }
        }
        return res;
    }
};
// @lc code=end

