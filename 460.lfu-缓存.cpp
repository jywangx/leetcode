/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
/* 双端链表 */
class DLinkedNode {
public:
    int          key;
    int          value;
    int          freq;
    DLinkedNode *next;
    DLinkedNode *prev;
    DLinkedNode(int key, int value, DLinkedNode *next) {
        this->key   = key;
        this->value = value;
        this->freq  = 1;
        this->next  = next;
        this->prev  = nullptr;
    }
};

class FreqElement {
public:
    int          freq;
    DLinkedNode *head;
    DLinkedNode *tail;
    FreqElement(int freq) {
        this->freq = freq;
        this->head = nullptr;
        this->tail = nullptr;
    }
};

class LFUCache {
private:

    int capacity;
    int size;
    int minFreq;

    unordered_map<int, FreqElement*> freqTable;
    unordered_map<int, DLinkedNode*> key2node;

public:
    LFUCache(int capacity) {
        this->capacity  = capacity;
        this->size      = 0;
        this->minFreq   = INT_MAX;
        this->freqTable = unordered_map<int, FreqElement*>();
        this->key2node  = unordered_map<int, DLinkedNode*>();
    }
    
    int get(int key) {
        if (key2node.find(key) != key2node.end()) {
            DLinkedNode *node = key2node[key];
            FreqElement *freq = freqTable[node->freq];
            if (node->prev == nullptr && node->next == nullptr) {
                freq->head = nullptr;
                freq->tail = nullptr;
                if (minFreq == node->freq) {
                    minFreq = node->freq + 1;
                }
            } else if (node->prev == nullptr) {
                freq->head = node->next;
                freq->head->prev = nullptr;
            } else if (node->next == nullptr) {
                freq->tail = node->prev;
                freq->tail->next = nullptr;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            
            node->freq ++;
            if (freqTable.find(node->freq) == freqTable.end()) {
                freqTable[node->freq] = new FreqElement(node->freq);
            }
            freq = freqTable[node->freq];
            if (freq->head == nullptr) {
                freq->head = node;
                freq->tail = node;
                node->prev = nullptr;
                node->next = nullptr;
            } else {
                node->prev = nullptr;
                node->next = freq->head;
                freq->head->prev = node;
                freq->head = node;
            }
            return node->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (key2node.find(key) != key2node.end()) {
            DLinkedNode *node = key2node[key];
            FreqElement *freq = freqTable[node->freq];
            if (node->prev == nullptr && node->next == nullptr) {
                freq->head = nullptr;
                freq->tail = nullptr;
                if (minFreq == node->freq) {
                    minFreq = node->freq + 1;
                }
            } else if(node->prev == nullptr) {
                freq->head = node->next;
                freq->head->prev = nullptr;
            } else if (node->next == nullptr) {
                freq->tail = node->prev;
                freq->tail->next = nullptr;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            
            node->freq ++;
            if (freqTable.find(node->freq) == freqTable.end()) {
                freqTable[node->freq] = new FreqElement(node->freq);
            }
            freq = freqTable[node->freq];
            if (freq->head == nullptr) {
                freq->head = node;
                freq->tail = node;
                node->prev = nullptr;
                node->next = nullptr;
            } else {
                node->prev = nullptr;
                node->next = freq->head;
                freq->head->prev = node;
                freq->head = node;
            }
            node->value = value;
        } else {
            if (size == capacity) {
                FreqElement *freq = freqTable[minFreq];
                DLinkedNode *node = freq->tail;
                if (node->prev == nullptr) {
                    freq->head = nullptr;
                    freq->tail = nullptr;
                } else {
                    freq->tail = node->prev;
                    freq->tail->next = nullptr;
                }
                key2node.erase(node->key);
                delete node;
                size --;
            }
            if (freqTable.find(1) == freqTable.end()) {
                freqTable[1] = new FreqElement(1);
            }
            FreqElement *freq = freqTable[1];
            DLinkedNode *node = new DLinkedNode(key, value, freq->head);
            if (freq->head == nullptr) {
                freq->head = node;
                freq->tail = node;
            } else {
                node->next = freq->head;
                freq->head->prev = node;
                freq->head = node;
            }
            key2node[key] = node;
            size ++;
            minFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

