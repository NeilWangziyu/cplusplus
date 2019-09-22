//
//  main.cpp
//  LRUCache
//
//  Created by 王子昱 on 2019/9/21.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <unordered_map>


using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }
        else
        {
            int val = it->second->second;
            list_tem.erase(it->second);
            list_tem.push_front(make_pair(key, val));
            m[key] = list_tem.begin();
            return val;
        }
        
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            list_tem.erase(it->second);
        }
        list_tem.push_front(make_pair(key, value));
        m[key] = list_tem.begin();
        if (list_tem.size() > cap) {
            int key = list_tem.back().first;
            m.erase(key);
            list_tem.pop_back();
        }
    }
private:
    int cap;
    unordered_map<int, list<pair<int,int>>::iterator> m ;
    list<pair<int, int>> list_tem;
};

class LRUCache2 {
private:
    struct CacheNode{
        int key;
        int value;
        CacheNode(int k, int v):key(k), value(v){}
    };
public:
    LRUCache2(int capacity) {
        this->capcity=capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key)==cacheMap.end()) return -1;
        //把当前访问的节点移到链表头部，并且更新map中该节点的地址
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key]=cacheList.begin();
        return cacheMap[key]->value;
        
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key)==cacheMap.end()){
            if(cacheList.size()==capcity){
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(CacheNode(key,value));
            cacheMap[key]=cacheList.begin();
        }
        else{
            cacheMap[key]->value=value;                                     //迭代器调用
            cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
            cacheMap[key]=cacheList.begin();
        }
        
        
    }
private:
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
    int capcity;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
