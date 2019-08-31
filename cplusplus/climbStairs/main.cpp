//
//  main.cpp
//  climbStairs
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
// 
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n == 2)
            return 2;
        else
        {
            int res = 0;
            int i = 1, j = 2;
            int k = 3;
            while (k <= n) {
                res = i + j;
                i = j;
                j = res;
                k++;
            }
            return res;
        }
        
    }
    int climbStairs0(int n) {
        if(n==1)
            return 1;
        if(n == 2)
            return 2;
        else
            return climbStairs(n-1)+climbStairs(n-2);
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    int res1 = s.climbStairs0(44);
    std::cout << res1 << std::endl;
    
    int res2 = s.climbStairs(44);
    std::cout << res2 << std::endl;
    
    
    return 0;
}
