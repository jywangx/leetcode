/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
private:
    struct LinkedNode {
        LinkedNode *prev;
        LinkedNode *next;
        int key;
        int value;
        // 构造函数，传入参数为prev和value，next置为nullptr
        LinkedNode(LinkedNode *prev, int key, int value) {
            this->prev = prev;
            this->next = nullptr;
            this->key  = key;
            this->value = value;
        }
    };
    // 哈希表，key为int，value为LinkedNode指针
    unordered_map<int, LinkedNode*> hash_map;
    LinkedNode *head;
    LinkedNode *tail;
    int size;
    int capacity;
public:
    LRUCache(int capacity) {
        this->head     = nullptr;
        this->tail     = nullptr;
        this->capacity = capacity;
        this->size     = 0;
        this->hash_map = unordered_map<int, LinkedNode*>();
    }
    
    int get(int key) {
        // printf("get(%d)\n", key);
        if (this->hash_map.find(key) != this->hash_map.end()) {
            // printf("find key %d\n", key);
            LinkedNode *node = this->hash_map[key];
            if (node == this->head) {
                return node->value;
            } else if (node == this->tail) {
                this->tail = node->prev;
                this->tail->next = nullptr;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            node->prev = nullptr;
            node->next = this->head;
            this->head->prev = node;
            this->head = node;
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // printf("put(%d, %d)\n", key, value);
        if (this->size == 0) {
            this->head = new LinkedNode(nullptr, key, value);
            this->tail = this->head;
            this->hash_map[key] = this->head;
            this->size ++;
        }
        // 检验key是否存在于hash map
        if (this->hash_map.find(key) != this->hash_map.end()) {
            // 如果存在，将该节点移动到链表头部
            LinkedNode *node = this->hash_map[key];
            node->value = value;
            if (node == this->head) {
                // 如果该节点已经在链表头部，直接返回
                return;
            } else if (node == this->tail) {
                // 如果该节点在链表尾部，将尾部指针指向该节点的前一个节点
                this->tail = node->prev;
                this->tail->next = nullptr;
            } else {
                // 如果该节点在链表中间，将该节点的前一个节点的next指针指向该节点的后一个节点
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            // 将该节点移动到链表头部
            node->prev = nullptr;
            node->next = this->head;
            this->head->prev = node;
            this->head = node;
        } else {
            // 如果不存在，将该节点插入到链表头部
            LinkedNode *node = new LinkedNode(nullptr, key, value);
            node->next = this->head;
            this->head->prev = node;
            this->head = node;
            this->hash_map[key] = node;
            this->size ++;
            // 如果链表长度超过capacity，删除链表尾部节点
            if (this->size > this->capacity) {
                LinkedNode *node = this->tail;
                this->tail = node->prev;
                this->tail->next = nullptr;
                this->hash_map.erase(node->key);
                delete node;
                this->size --;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

