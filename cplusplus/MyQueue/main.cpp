//
//  main.cpp
//  MyQueue
//
//  Created by 王子昱 on 2019/6/28.
//  Copyright © 2019 王子昱. All rights reserved.
//
#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::map;
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ans = s2.top();
        s2.pop();
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ans = s2.top();
        return ans;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    MyQueue* obj = new MyQueue();
    
    obj->push(10);
    obj->push(11);
    obj->push(9);

    int param_2 = obj->pop();
    cout << param_2 <<endl;
    
    int param_3 = obj->peek();
    cout <<param_3 <<endl;
    
    
    bool param_4 = obj->empty();
    cout << param_4 <<endl;
    
    return 0;
}
