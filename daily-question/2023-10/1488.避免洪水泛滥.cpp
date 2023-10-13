/*
 * @lc app=leetcode.cn id=1488 lang=cpp
 *
 * [1488] 避免洪水泛滥
 */

// @lc code=start
class Solution {
private:
    struct Flood {
        int day;
        int lake;
        Flood(int d, int l) : day(d), lake(l) {}
    };
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        queue<int> dry;
        deque<Flood> flood;
        stack<Flood> tmp;
        unordered_map<int, int> full;
        for (int i = 0; i < n; i ++) {
            if (rains[i] == 0) {
                dry.push(i);
            } else if (full.count(rains[i]) == 0) {
                full[rains[i]] = i;
            } else {
                flood.push_back(Flood(i, rains[i]));
            }
        }
        if (flood.size() > dry.size()) {
            return {};
        }
        if (dry.empty()) {
            return ans;
        }
        Flood f = flood.front();
        int d = dry.front();
        while (!flood.empty() && !dry.empty()) {
            if (f.day < d) {
                return {};
            } else if (full[f.lake] > d) {
                Flood tf = f;
                while (full[tf.lake] > d) {
                    tmp.push(tf);
                    flood.pop_front();
                    if (!flood.empty()) {
                        tf = flood.front();
                    } else {
                        break;
                    }
                }
                if (full[tf.lake] < d) {
                    ans[d] = tf.lake;
                    full[tf.lake] = tf.day;
                    flood.pop_front();
                } else {
                    ans[d] = 1;
                }
                
                dry.pop();
                while (!tmp.empty()) {
                    flood.push_front(tmp.top());
                    tmp.pop();
                }
                if (!dry.empty()) {
                    d = dry.front();
                }
            } else {
                ans[d] = f.lake;
                full[f.lake] = f.day;
                dry.pop();
                flood.pop_front();
                if (!flood.empty()) {
                    f = flood.front();
                }
                if (!dry.empty()) {
                    d = dry.front();
                }
            }
        }
        if (!dry.empty()) {
            while (!dry.empty()) {
                ans[dry.front()] = 1;
                dry.pop();
            }
        } else if (!flood.empty()) {
            return {};
        }
        return ans;
    }
};
// @lc code=end

