/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *p = head, *l;
        stack<ListNode*> s;
        for (int i = 1; i < left - 1; i++) {
            p = p->next;
        }
        l = p;
        if (left > 1) {
            p = p->next;
        }
        for (int i = left; i <= right; i++) {
            s.push(p);
            p = p->next;
        }
        ListNode *next = s.top()->next;
        if (left == 1) head = s.top();
        else l->next = s.top();
        while (!s.empty()) {
            p = s.top();
            s.pop();
            p->next = s.empty() ? next : s.top();
        }
        return head;
    }
};
// @lc code=end

