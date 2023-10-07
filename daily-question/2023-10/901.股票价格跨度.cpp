/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
private:
    struct PriceNode {
        int val;
        int spanSize;
        PriceNode *prev;
        PriceNode *spanPrev;
    };
    PriceNode *tail;
public:
    StockSpanner() {
        tail = nullptr;
    }
    
    int next(int price) {
        PriceNode *node = new PriceNode();
        node->val = price;
        node->spanSize = 1;
        node->prev = nullptr;
        node->spanPrev = nullptr;
        if (tail == nullptr) {
            tail = node;
        } else {
            PriceNode *prev = tail;
            node->prev = tail;
            tail = node;
            while (prev != nullptr && prev->val <= price) {
                node->spanSize += prev->spanSize;
                if (prev->spanPrev != nullptr) {
                    node->spanPrev = prev->spanPrev;
                    prev = prev->spanPrev->prev;
                } else {
                    node->spanPrev = prev;
                    prev = prev->prev;
                }
            }            
        }
        return node->spanSize;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

