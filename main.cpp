#include "LRUTemplate.h"
int main() {
    LRUCache<int,int> *lru = new LRUCache<int,int>(3);
    lru->Set(2,1);
    std::cout << lru->Get(2) << std::endl;
//    LRUCache *lruCache = new LRUCache(3);
//    lruCache->Set(2,1);
//    lruCache->set(1,1);
//    std::cout << lruCache->get(1) <<std::endl;
//    lruCache->set(4,1);
//    std::cout << lruCache->get(4) <<std::endl;
//    std::cout << lruCache->get(3) <<std::endl;
    return 0;
}