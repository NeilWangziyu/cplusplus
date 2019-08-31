//
//  main.cpp
//  maxProfitII
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        vector<int> DP_sell(prices.size());
        vector<int> DP_buy(prices.size());
        
        DP_sell[0] = 0;
        DP_buy[0] = -prices[0];
        
        for (int i = 1; i < prices.size(); i ++) {
            DP_buy[i] = max(DP_buy[i-1], DP_sell[i-1] - prices[i]);
            DP_sell[i] = max(DP_sell[i-1], DP_buy[i-1] + prices[i]);
        }
        return DP_sell.back();
    }
    
    
    int maxProfit2(vector<int>& prices) {
//        only with O(1) space
        if(prices.size() == 0) return 0 ;
        int sum = 0 , bug = prices[0] , sell = prices[0] ;
        for(int i = 1 ; i < prices.size() ; i++){
            if(prices[i] > bug){
                
                sell = prices[i] ;
                if( i == prices.size() - 1 ){
                    sum = sum + sell - bug ;
                    break;
                }
                
                if((i < prices.size() - 1 && prices[i + 1] < prices[i] ) ){
                    sum = sum + sell - bug ;
                    bug = prices[i + 1] ;
                }
                
            }else {
                bug = sell = prices[i] ;
            }
        }
        
        return sum ;
        
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    int res = s.maxProfit(prices);
    std::cout << res << endl;
    
    prices = {1,2,3,4,5};
    res = s.maxProfit(prices);
    std::cout << res << endl;

    
    
    return 0;
}
