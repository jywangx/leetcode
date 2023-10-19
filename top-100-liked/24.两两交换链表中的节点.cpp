/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p;
        ListNode **lnp = &head;
        for (p = head; p && p->next;) {
            ListNode *np = p->next;
            p->next = np->next;
            np->next = p;
            *lnp = np;
            lnp = &(p->next);
            p = p->next;
        }
        return head;
    }
};
// @lc code=end

