//
//  main.cpp
//  maxSubArray
//
//  Created by 王子昱 on 2019/7/12.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        vector<int> dp(nums.size(),0);
        int res = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            res = max(res, dp[i]);
        }
        
        
        return res;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    int res = s.maxSubArray(nums);
    cout <<  res << endl;
    
    
    return 0;
}
