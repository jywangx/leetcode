/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> map;
        if (head == nullptr) return nullptr;
        Node *newh = new Node(head->val);
        Node *newt = newh;
        map[head] = newt;
        newt->random = head->random;
        Node *h = head;
        while (h->next != nullptr) {
            Node *temp = new Node(h->next->val);
            temp->random = h->next->random;
            newt->next = temp;
            newt = temp;
            h = h->next;
            map[h] = newt;
        }
        h = newh;
        while (h != nullptr) {
            h->random = map[h->random];
            h = h->next;
        }
        return newh;
    }
};
// @lc code=end

