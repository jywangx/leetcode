/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
private:
    struct NumInSeq {
        int rangeLeft;
        int rangeRight;
        // NumInSeq(int l, int r): rangeLeft(l), rangeRight(r) {};
    };
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        int n = nums.size();
        unordered_map<int, NumInSeq> nmap;
        for (int &num: nums) {
            if (nmap.find(num) != nmap.end()) continue;
            if (nmap.find(num-1) != nmap.end() && nmap.find(num+1) != nmap.end()) { 
                int ridx = nmap[num+1].rangeRight;
                int lidx = nmap[num-1].rangeLeft;
                nmap[lidx].rangeRight = ridx;
                nmap[ridx].rangeLeft  = lidx;
                nmap[num] = {lidx, ridx};
                maxLen = max(
                    maxLen, 
                    ridx - lidx + 1
                );
            } else if (nmap.find(num-1) != nmap.end()) {
                int lidx = nmap[num-1].rangeLeft;
                nmap[lidx].rangeRight = num;
                nmap[num] = {nmap[num-1].rangeLeft, num};
                maxLen = max(
                    maxLen, 
                    num - lidx + 1
                );
            } else if (nmap.find(num+1) != nmap.end()) {
                int ridx = nmap[num+1].rangeRight;
                nmap[ridx].rangeLeft = num;
                nmap[num] = {num, nmap[num+1].rangeRight};
                maxLen = max(
                    maxLen, 
                    ridx - num + 1
                );
            } else {
                nmap[num] = {num, num};
                maxLen = max(maxLen, 1);
            }
        }
        return maxLen;
    }
};
// @lc code=end

