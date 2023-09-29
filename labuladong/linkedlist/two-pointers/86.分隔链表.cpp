/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lh = nullptr, *gh = nullptr;
        ListNode **lp = &lh, **gp = &gh;
        for (ListNode *p = head; p != nullptr; p = p->next) {
            if (p->val < x) {
                (*lp) = new ListNode(p->val);
                lp = &((*lp)->next);
            } else {
                (*gp) = new ListNode(p->val);
                gp = &((*gp)->next);
            }
        }
        *lp = gh;
        return lh;
    }
};
// @lc code=end

