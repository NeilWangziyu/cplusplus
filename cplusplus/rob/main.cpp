//
//  main.cpp
//  rob
//
//  Created by 王子昱 on 2019/7/16.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int size = nums.size();
        
        vector<int> dp(size+1, 0);
        dp[1] = nums[0];
        for(int i = 2; i < size+1; i ++ )
        {
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        return dp.back();
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
