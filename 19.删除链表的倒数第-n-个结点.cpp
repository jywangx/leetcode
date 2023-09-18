/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // help me debug
        ListNode **lkp = &head, *lp = head, **rmpp;
        for (int i = 0; i < n && lp != nullptr; i ++, lp = lp->next);
        for (
            rmpp = lkp; 
            lp != nullptr; 
            lp = lp->next, rmpp = &(*lkp)->next, lkp = &(*lkp)->next
        );
        *rmpp = (*lkp)->next;
        return head;
    }
};
// @lc code=end

