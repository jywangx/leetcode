/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 元素为ListNode*的最小堆min_heap
        auto cmp = [](ListNode* a, ListNode* b) { 
            return a->val > b->val; 
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> min_heap(cmp);
        for (auto list : lists) {
            if (list != nullptr) {
                min_heap.push(list);
            }
        }
        ListNode *head = nullptr, **lpp = &head;
        while (!min_heap.empty()) {
            ListNode *p = min_heap.top();
            min_heap.pop();
            *lpp = new ListNode(p->val);
            lpp = &((*lpp)->next);
            if (p->next != nullptr) {
                min_heap.push(p->next);
            }
        }
        return head;
    }
};
// @lc code=end

