//
//  main.cpp
//  canJump
//
//  Created by 王子昱 on 2019/9/24.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0)
            return true;
        int max_len = 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(dp[i] == 1)
            {
                for(int j = i+1;j <= i + nums[i]; j++)
                {
                    if(j < nums.size())
                        dp[j] = true;
                }
            }
        }
        return dp.back()==1?true:false;
    }
    
    bool canJump2(vector<int>& nums) {
        int max_forward_index = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            max_forward_index = max(max_forward_index, i + nums[i]);
            if(i >= max_forward_index || max_forward_index >= nums.size() - 1) break;
        }
        return max_forward_index >= nums.size() - 1;
    }
    
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

