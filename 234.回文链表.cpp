/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        stack<int> stk;
        while (fast != nullptr && fast->next != nullptr) {
            stk.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr) slow = slow->next;
        while (slow != nullptr) {
            if (stk.top() != slow->val) return false;
            stk.pop();
            slow = slow->next;
        }
        return true;
    }
};
// @lc code=end

