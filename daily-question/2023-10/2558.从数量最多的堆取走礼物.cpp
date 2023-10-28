/*
 * @lc app=leetcode.cn id=2558 lang=cpp
 *
 * [2558] 从数量最多的堆取走礼物
 */

// @lc code=start
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap;
        long long sum = 0;
        for (int &g: gifts) {
            maxHeap.push(g);
            sum += g;
        }

        for (int i = 0; i < k; i ++) {
            int x = maxHeap.top();
            maxHeap.pop();
            sum -= x;
            sum += sqrt(x);
            maxHeap.push(sqrt(x));
        }
        return sum;
    }
};
// @lc code=end

