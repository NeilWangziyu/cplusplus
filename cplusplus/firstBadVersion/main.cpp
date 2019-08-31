//
//  main.cpp
//  firstBadVersion
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long lo = 1;
        long hi = n;
        while(lo < hi)
        {
            long mid = (lo + hi) / 2;
            // cout << lo << " " << hi << endl;
            if(isBadVersion(mid))
            {
                if(isBadVersion(mid-1))
                {
                    hi = mid;
                }
                else
                    return mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return hi;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
