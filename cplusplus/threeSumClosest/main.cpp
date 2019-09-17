//
//  main.cpp
//  threeSumClosest
//
//  Created by 王子昱 on 2019/9/16.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closed_sum = -10000;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i < nums.size()-2; i ++) {
            int l = i+1;
            int r = nums.size()-1;
            while (l < r) {
                if (abs(closed_sum-target) >= abs(nums[i]+nums[l]+nums[r]-target)) {
                    closed_sum = nums[i]+nums[l]+nums[r];
                }
                if (closed_sum == target) {
                    return closed_sum;
                }
                if (nums[i]+nums[l]+nums[r] >= target) {
                    r -= 1;
                }
                else
                    l += 1;
            }
        }
        
        return closed_sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
