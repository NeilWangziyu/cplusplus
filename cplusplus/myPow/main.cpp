//
//  main.cpp
//  myPow
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n ; i != 0; i = i / 2) {
//            std::cout << i << std::endl;
            if(i % 2 == 0)
            {
//                even i
                x = x * x;
            }
            else
            {
                res = res * x;
            }
        }
        return n < 0 ? 1 / res : res;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    
    std::cout << s.myPow(1.5, 5) << std::endl;
    
    return 0;
}
