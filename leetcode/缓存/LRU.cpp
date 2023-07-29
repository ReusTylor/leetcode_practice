/*
    使用双向链表 + 哈希实现LRU
    双向链表存储数据，哈希实现随即访问
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

struct DLinked {
    int key, value;
    DLinked* prev;
    DLinked* next;
    DLinked(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinked(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};


class LRUCache
{
private:
    unordered_map<int, DLinked*> cache;
    DLinked* head;
    DLinked* tail;
    // 当前双向链表的大小
    int size;
    // 双向链表的容量
    int capacity;
public:
    LRUCache(int _capicity) : capacity(_capicity), size(0) {
        head = new DLinked();
        tail = new DLinked();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){
        if(!cache.count(key)){
            return -1;
        }
        DLinked* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value){
        // 如果key不存在
        if(!cache.count(key)){
            DLinked* node = new DLinked(key, value);
            cache[key] = node;
            addToHead(node);
            size++;
            if(size > capacity){
                DLinked* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
            // 如果key存在，更新值即可
        }else{
            DLinked* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void moveToHead(DLinked* node){
        // remove  add
        removeNode(node);
        addToHead(node);
    }

    void addToHead(DLinked* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinked* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    DLinked* removeTail(){
        DLinked* node = tail->prev;
        removeNode(node);
        return node;
    }
};



