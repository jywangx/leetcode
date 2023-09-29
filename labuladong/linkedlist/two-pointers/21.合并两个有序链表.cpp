/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *lp;
        ListNode **lpp = &lp;
        while (list1 != nullptr || list2 != nullptr) {
            int val = 0x7fffffff;
            if (list1 == nullptr) {
                val = list2->val;
                list2 = list2->next;
            } else if (list2 == nullptr) {
                val = list1->val;
                list1 = list1->next;
            } else if (list1->val < list2->val) {
                val = list1->val;
                list1 = list1->next;
            } else {
                val = list2->val;
                list2 = list2->next;
            }
            *lpp = new ListNode(val);
            lpp = &((*lpp)->next);
        }
        return lp;
    }
};
// @lc code=end

