/*
 * @lc app=leetcode.cn id=2034 lang=cpp
 *
 * [2034] 股票价格波动
 */

// @lc code=start
class StockPrice {
private:
    struct StokePrice{
        int price;
        int timestamp;
    };
    struct CompareMax {
        bool operator()(const StokePrice& a, const StokePrice& b) {
            return a.price < b.price; // 这里使用 < 来构建最大堆
        }
    };
    struct CompareMin {
        bool operator()(const StokePrice& a, const StokePrice& b) {
            return a.price > b.price; // 这里使用 > 来构建最小堆
        }
    };

    int minPrice;
    priority_queue<StokePrice, vector<StokePrice>, CompareMin> minHeap;
    int maxPrice;
    priority_queue<StokePrice, vector<StokePrice>, CompareMax> maxHeap;
    unordered_map<int, int> timestamp2price;
    int latestTimestamp;
    int currentPrice;
public:
    StockPrice() {
        minPrice = INT_MAX;
        maxPrice = INT_MIN;
        latestTimestamp = -1;
        currentPrice = 0;
    }
    
    void update(int timestamp, int price) {
        maxHeap.push({price, timestamp});
        minHeap.push({price, timestamp});
        timestamp2price[timestamp] = price;
        if (timestamp >= latestTimestamp) {
            latestTimestamp = timestamp;
            currentPrice = price;
        }
    }
    
    int current() {
        return currentPrice;
    }
    
    int maximum() {
        while (timestamp2price[maxHeap.top().timestamp] != maxHeap.top().price) {
            maxHeap.pop();
        }
        return maxHeap.top().price;
    }
    
    int minimum() {
        while (timestamp2price[minHeap.top().timestamp] != minHeap.top().price) {
            minHeap.pop();
        }
        return minHeap.top().price;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end

