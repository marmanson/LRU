//
// Created by 王博 on 2020/4/10.
//

#ifndef LRU_LRU_H_H
#define LRU_LRU_H_H
#include <iostream>
#include <map>

struct CacheNode{
    int key;
    int value;
    CacheNode *pre,*next;
    CacheNode(int k,int v) : key(k),value(v),pre(NULL),next(NULL) {}
};

class LRUCache{
private:
    int size;
    CacheNode *head, *tail;
    std::map<int,CacheNode *> mp;
public:
    LRUCache(int capacity){
        size = capacity;
        head = NULL;
        tail = NULL;
    }

    int get(int key){
        std::map<int,CacheNode *>::iterator it = mp.find(key);
        if (it != mp.end()){
            CacheNode *node = it->second;
            remove(node);
            setHead(node);
            return node->value;
        }else{
            return -1;
        }
    }

    void set(int key,int value){
        std::map<int,CacheNode *>::iterator it = mp.find(key);
        if (it != mp.end()){
            CacheNode *node = it->second;
            node->value = value;
            remove(node);
            setHead(node);
        }else{
            CacheNode *newNode = new CacheNode(key,value);
            if (mp.size() >= size){
                std::map<int,CacheNode*>::iterator iter = mp.find(tail->key);
                remove(tail);
                mp.erase(iter);
            }
            setHead(newNode);
            mp[key] = newNode;
        }
    }

    void remove(CacheNode *node){
        if (node->pre != NULL){
            node->pre->next = node->next;
        }else{
            head = node->next;
        }
        if (node->next != NULL){
            node->next->pre = node->pre;
        }else{
            tail = node->pre;
        }
    }

    void setHead(CacheNode *node){
        node->next = head;
        node->pre = NULL;
        if(head != NULL){
            head->pre = node;
        }
        head = node;
        if(tail == NULL){
            tail = head;
        }
    }
};
#endif //LRU_LRU_H_H
