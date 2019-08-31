//
//  main.cpp
//  rotate
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0)
        {
            return ;
            
        }
        if(nums.size() < 1)
        {
            return;
        }
        
        k = k % nums.size();
        
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
    
    
    void reverse(vector<int>& nums, int start, int end)
    {
        while (start < end) {
            int tem = nums[start];
            nums[start] = nums[end];
            nums[end] = tem;
            start += 1;
            end -= 1;
        }
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    s.rotate(nums, k);
    for (auto i : nums) {
        std::cout << i << endl;
    }
    
    return 0;
}
