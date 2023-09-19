/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        bool firstNullA = true, firstNullB = true;
        while (!(
            pA == nullptr && pB == nullptr
            && !firstNullA && firstNullB
        )) {
            if (pA == nullptr && firstNullA) {
                pA = headB;
                firstNullA = false;
            }
            if (pB == nullptr && firstNullB) {
                pB = headA;
                firstNullB = false;
            }
            if (pA == pB) return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return nullptr;
    }
};
// @lc code=end

