/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> s;
        ListNode **p2rhead = &head;
        ListNode *stackInP = head;
        while (true) {
            for (int i = 0; i < k; i ++) {
                if (stackInP == nullptr) {
                    return head;
                }
                s.push(stackInP);
                stackInP = stackInP->next;
            }
            ListNode *next = s.top()->next;
            *p2rhead = s.top();
            ListNode *stackOutP;
            for (int i = 0; i < k; i ++) {
                stackOutP = s.top();
                s.pop();
                stackOutP->next = s.empty() ? next : s.top();
            }
            p2rhead = &(stackOutP->next);
        }
        return head;
    }
};
// @lc code=end

