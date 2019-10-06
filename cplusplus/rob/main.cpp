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
    
    int rob2(vector<int>& nums) {
        int size = nums.size();
        //后面直接用到nums[2]，因此需要单独判断nums长度小于等于2的情况，否则若输入的nums长度小于等于2则编译不过
        if (size == 0){
            return 0;
        }
        if (size == 1){
            return nums[0];
        }
        if (size == 2){
            return max(nums[0], nums[1]);
        }
        int dp1[size];
        int dp2[size];
        //参考第198题打家劫舍，考虑本题，分两种情况讨论，去掉第一家和去掉最后一家，然后取两种方法的最大值
        //状态转移方程：dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i])
        //注意由于去掉一家了之后，定义的dp数组就会少使用一项，因此一个不使用第一项，一个不使用最后一项，注意for循环的起始和结束位置
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
        for (int i = 2; i < size - 1; i++){
            dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i]);
        }
        for (int i = 3; i < size; i++){
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);
        }
        return max(dp1[size-2], dp2[size-1]);
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
