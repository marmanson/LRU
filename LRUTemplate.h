//
// Created by 王博 on 2020/4/10.
//

#ifndef LRU_LRUTEMPLATE_H
#define LRU_LRUTEMPLATE_H
#include <iostream>
#include <map>

template <typename T,typename U>
class LRUCache{
private:
    struct LruNode{
        T key;
        U value;
        LruNode* pre;
        LruNode* next;
        LruNode(T k,U v): key(k),value(v),pre(nullptr),next(nullptr){}
    };
    int size;
    LruNode *head,*tail;
    std::map<T,LruNode*> mp;
public:
    typedef typename std::map<T,LruNode*>::iterator iterator;
    LRUCache(int s):size(s),head(nullptr),tail(nullptr){}
    U Get(T key){
        iterator it = mp.find(key);
        if(it != mp.end()){
            LruNode* node = it->second;
            remove(node);
            setHead(node);
            return node->value;
        }else{
            return 0;
        }
    }

    void Set(T key,U value){
        iterator it = mp.find(key);
        if(it != mp.end()){
            LruNode* node = it->second;
            node->value = value;
            remove(node);
            setHead(node);
        }else{
            LruNode *node = new LruNode(key,value);
            if(mp.size() >= size){
                iterator it = mp.find(tail->key);
                remove(tail);
                mp.erase(it);
            }
            setHead(node);
            mp[key] = node;
        }
    }
    void remove(LruNode *node){
        if(node->pre != nullptr){
            node->pre->next = node->next;
        }else{
            head = node->next;
        }
        if(node->next != nullptr){
            node->next->pre = node->pre;
        }else{
            tail = node->pre;
        }
        free(node);
    }

    void setHead(LruNode *node){
        node->pre = nullptr;
        node->next = head;
        if(head != nullptr){
            head->pre = node;
        }
        head = node;
        if(tail == nullptr){
            tail = head;
        }
    }
};
#endif //LRU_LRUTEMPLATE_H
