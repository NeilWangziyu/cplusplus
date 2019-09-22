//
//  main.cpp
//  MyStack
//
//  Created by 王子昱 on 2019/9/22.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;


class MyStack {
private:
    queue<int> que;
public:
    /** Initialize your data structure here. */
    MyStack() {}
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> temp;
        int t=0;
        int length=que.size();
        for(int i=0; i<length; i++)
        {
            t=que.front();
            que.pop();
            temp.push(t);
        }
        //     temp.push(que.pop());
        que.push(x);
        for(int i=0; i<length; i++)
        {
            t = temp.front();
            que.push(t);
            temp.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(que.empty())
            return 0;
        int t=que.front();
        que.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        if(que.empty())
            return 0;
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
