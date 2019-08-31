//
//  main.cpp
//  maxProfitI
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
#include <iostream>
#include <vector>


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int prev_min = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i ++) {
            if(prices[i] - prev_min > max_profit)
            {
                max_profit = prices[i] - prev_min;
            }
            
            if(prev_min > prices[i])
            {
                prev_min = prices[i];
            }
        }
        return max_profit;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
