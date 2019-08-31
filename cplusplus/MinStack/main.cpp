//
//  main.cpp
//  MinStack
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class MinStack {
    vector<int> stack;
    vector<int> min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        stack.push_back(x);
        if(min_stack.size() == 0)
        {
            min_stack.push_back(x);
        }
        else
        {
            if (x < min_stack.back())
            {
                min_stack.push_back(x);
            }
            else
            {
                min_stack.push_back(min_stack.back());
            }
        }
        
        
    }
    
    void pop() {
        stack.pop_back();
        min_stack.pop_back();
        
    }
    
    int top() {
        return stack.back();
        
    }
    
    int getMin() {
        return min_stack.back();
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
