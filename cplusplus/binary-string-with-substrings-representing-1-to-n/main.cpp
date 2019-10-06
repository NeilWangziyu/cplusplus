//
//  main.cpp
//  binary-string-with-substrings-representing-1-to-n
//
//  Created by 王子昱 on 2019/9/27.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool queryString(string S, int N) {
        for(int i = 1; i < N + 1; i++)
        {
            string tem = int_to_binary(i);
            // cout << tem;
            if(S.find(tem) == -1)
            {
                return false;
            }
        }
        return true;
    }
    
    string int_to_binary(int num)
    {
        string res;
        while(num != 0)
        {
            int mod = num % 2;
            num = num / 2;
            res = to_string(mod) + res;
        }
        return res;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    int input_num = 5;
    string t = "1111000101";
    cout << s.queryString(t, input_num);
    
    return 0;
}
