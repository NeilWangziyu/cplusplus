//
//  main.cpp
//  move-zeroes
//
//  Created by 王子昱 on 2019/9/23.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() < 2)
            return;
        
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i += 1;
            }
        }
        for (; i < nums.size(); i++) {
            nums[i] = 0;
        }
        return;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
