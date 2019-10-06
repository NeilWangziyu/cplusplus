//
//  main.cpp
//  integer-replacement
//
//  Created by 王子昱 on 2019/9/28.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int integerReplacement0(int n) {

        if(n == 1)
        {
            return 0;
        }

        
        if(n % 2 == 0)
        {
            long res = integerReplacement0(n >> 1)+1;

            return res;        }
        else
            
        {
            long res2 =min(integerReplacement0(n-1), integerReplacement0(n+1))+1;
            return res2;
        }
    }
    
    int integerReplacement(int n) {
        int count = 0;
        while (n != 1) {
            if(n == 3)
            {
                count += 2;
                break;
            }
            if (n == 2147483647) {
                return 32;
            }
            if (n & 1 == 0) {
                n >>= 1;
            }
            else
            {
                if ((n & 2) == 2) {
                    n += 1;
                }else
                {
                    n -= 1;
                }
                
            }
            count += 1;
        }
        return count;
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
