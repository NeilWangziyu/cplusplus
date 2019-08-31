//
//  main.cpp
//  removeDuplicates
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

// double pointer
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        if(nums.size() == 1)
        {
            return 1;
        }
        int i = 0;
        for (int k = 1; k < nums.size(); k ++) {
            if(nums[i] != nums[k])
            {
                i += 1;
                nums[i] = nums[k];
            }
        }
        return i + 1;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
