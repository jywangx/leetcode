/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int res_l, res_r, res_len = 0;
        int n = s.size();
        for (int mid = 0; mid < n; mid ++) {
            for (int i = 0; i + mid < n && mid - i >= 0; i ++) {
                if (s[mid - i] != s[mid + i]) break;
                if (2 * i + 1 > res_len) {
                    res_len = 2 * i + 1;
                    res_l = mid - i;
                    res_r = mid + i;
                }
            }

            for (
                int mid_l = mid, mid_r = mid+1; 
                mid_l >= 0 && mid_r < n; 
                mid_l --, mid_r ++
            ) {
                if (s[mid_l] != s[mid_r]) break;
                if (mid_r - mid_l + 1 > res_len) {
                    res_len = mid_r - mid_l + 1;
                    res_l = mid_l;
                    res_r = mid_r;
                }
            }
            
            if (res_len >= 2*(n-mid) + 1) break;
        }
        return s.substr(res_l, res_len);
    }
};
// @lc code=end

