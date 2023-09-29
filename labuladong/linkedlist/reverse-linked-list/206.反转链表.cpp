/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        stack<ListNode *> s;
        ListNode *p = head, *real_head;
        for (; p != nullptr; p = p->next) {
            s.push(p);
        }
        real_head = s.top();
        while (!s.empty()) {
            p = s.top();
            s.pop();
            p->next = s.empty() ? nullptr : s.top();
        }
        return real_head;
    }
};
// @lc code=end

