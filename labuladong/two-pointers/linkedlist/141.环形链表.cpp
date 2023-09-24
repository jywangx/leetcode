/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *fast = head, *slow = head;
        do {
            fast = fast->next;
            slow = slow->next;
            if (slow == nullptr) return false;
            slow = slow->next;
            if (slow == nullptr) return false;
        } while (fast != slow);
        return true;
    }
};
// @lc code=end

