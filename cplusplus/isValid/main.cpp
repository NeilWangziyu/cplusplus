//
//  main.cpp
//  isValid
//
//  Created by 王子昱 on 2019/9/12.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) {
            return true;
        }
        
        vector<char> stack;
        
        for (char c : s) {
            if (stack.size() == 0)
            {
                if (c == '}' || c == ']' || c == ')') {
                    return false;
                }
                stack.push_back(c);
            }
            else
            {
                if (c == '{' || c == '[' || c == '(') {
                    stack.push_back(c);
                }
                else if (c == ')')
                {
                    if (stack.back() != '(') {
                        return false;
                    }
                    else
                        stack.pop_back();
                }
                else if (c == ']')
                {
                    if (stack.back() != '[') {
                        return false;
                    }
                    else
                        stack.pop_back();
                    
                }
                else
                {
                    if (stack.back() != '{') {
                        return false;
                    }
                    else
                        stack.pop_back();
                    
                }
            }
        }
        if (stack.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

