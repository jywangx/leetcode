/*
 * @lc app=leetcode.cn id=2251 lang=cpp
 *
 * [2251] 花期内花的数目
 */

// @lc code=start
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> cnt;
        for (auto &flower : flowers) {
            cnt[flower[0]]++;
            cnt[flower[1] + 1]--;
        }
        int m = people.size();
        vector<int> indices(m);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return people[a] < people[b];
        });

        vector<int> ans(m);
        int curr = 0;
        auto it = cnt.begin();
        for (int x : indices) {
            while (it != cnt.end() && it->first <= people[x]) {
                curr += it->second;
                it++;
            }
            ans[x] = curr;
        }
        return ans;
    }
};
// @lc code=end

