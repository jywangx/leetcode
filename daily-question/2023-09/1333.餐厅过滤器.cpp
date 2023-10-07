/*
 * @lc app=leetcode.cn id=1333 lang=cpp
 *
 * [1333] 餐厅过滤器
 */

// @lc code=start
class Solution {
public:
    struct restaurant {
        int id;
        int rating;
        bool operator<(const restaurant &r) const {
            if (rating == r.rating) {
                return id > r.id;
            }
            return rating > r.rating;
        }
    };
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<restaurant> restrts;
        for (vector<int> &restrt : restaurants) {
            if (
                (veganFriendly == 0 || restrt[2] == 1) &&
                restrt[3] <= maxPrice &&
                restrt[4] <= maxDistance
            ) {
                restrts.push_back({restrt[0], restrt[1]});
            }
        }
        sort(restrts.begin(), restrts.end());
        vector<int> res;
        for (restaurant &restrt : restrts) {
            res.push_back(restrt.id);
        }
        return res;
    }
};
// @lc code=end

