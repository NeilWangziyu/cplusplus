//
//  main.cpp
//  missingNumber
//
//  Created by 王子昱 on 2019/9/1.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.back() == nums.size()-1)
            return nums.size();
        
        int i= 0;
        int j = nums.size()-1;
        while(i < j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] > mid)
                j = mid;
            else
                i = mid + 1;
        }
        return (i + j) / 2;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
