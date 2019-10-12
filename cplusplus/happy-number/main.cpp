//
//  main.cpp
//  happy-number
//
//  Created by 王子昱 on 2019/10/12.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> checked;
        
        if(n == 1)
            return true;
        
        checked.insert(n);
        int next_num = 0;

        while(true)
        {
            while(n != 0)
            {
                next_num += pow(n % 10, 2);
                n = n / 10;
            }
            if(next_num == 1)
            {
                return true;
            }
            else
            {
                if(checked.find(next_num) != checked.end())
                {
                    return false;
                }
                else
                    checked.insert(next_num);
            }
            n = next_num;
            next_num = 0;
            
        }
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
