/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
private:
    static inline bool sContainT(vector<int>& sCnt, vector<int>& tCnt, unordered_set<char>& tSet) {
        for (char c : tSet) {
            if (c >= 'a' && c <= 'z') {
                if (sCnt[c-'a'] < tCnt[c-'a']) {
                    return false;
                }
            } else {
                if (sCnt[c-'A'+26] < tCnt[c-'A'+26]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int ns = s.size(), nt = t.size();
        if (nt > ns) return "";
        vector<int> sCnt(52, 0);
        vector<int> tCnt(52, 0);
        int minL = INT_MAX, mini, minj;
        unordered_set<char> tSet;
        for (char c : t) {
            tSet.insert(c);
            if (c >= 'a' && c <= 'z') {
                tCnt[c-'a'] ++;
            } else {
                tCnt[c-'A'+26] ++;
            }
        }
        if (s[0] >= 'a' && s[0] <= 'z') {
            sCnt[s[0]-'a'] ++;
        } else {
            sCnt[s[0]-'A'+26] ++;
        }

        for (int i = 0, j = 0; j < ns; ) {
            while (!sContainT(sCnt, tCnt, tSet) && j < ns-1) {
                j ++;
                if (s[j] >= 'a' && s[j] <= 'z') {
                    sCnt[s[j]-'a'] ++;
                } else {
                    sCnt[s[j]-'A'+26] ++;
                }
            }
            if (!sContainT(sCnt, tCnt, tSet)) break;
            while (sContainT(sCnt, tCnt,tSet) && i < j) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    sCnt[s[i]-'a'] --;
                } else {
                    sCnt[s[i]-'A'+26] --;
                }
                i ++;
            }
            if (i < j) {
                if (j-i+2 < minL) {
                    minL = j-i+2;
                    mini = i-1;
                    minj = j;
                }
            } else if (nt == 1) {
                return s.substr(i, 1);
            } else {
                if (2 < minL) {
                    minL = 2;
                    mini = i-1;
                    minj = j;
                }
            }
            if (minL == nt) break;
        }
        if (minL == INT_MAX) return "";
        return s.substr(mini, minL);
    }
};
// @lc code=end

