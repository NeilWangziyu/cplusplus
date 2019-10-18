//
//  main.cpp
//  problems/best-time-to-buy-and-sell-stock-with-transaction-fee
//
//  Created by 王子昱 on 2019/10/18.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int lenth = prices.size();
        if (lenth == 0) {
            return 0;
        }
        vector<int> buy(lenth, 0);
        vector<int> sold(lenth, 0);
        buy[0] = - prices[0];
        for (int i = 1; i < lenth; i ++) {
            buy[i] = max(sold[i-1] - prices[i], buy[i-1]);
            sold[i] = max(buy[i-1] + prices[i] - fee, sold[i-1]);
        }
        return sold[lenth-1];

    }
    
    int maxProfit_2(vector<int>& prices, int fee) {
        int lenth = prices.size();
        if (lenth == 0) {
            return 0;
        }
        
        int buy = - prices[0];
        
        int sold = 0;
        
        for (int i = 1; i < lenth; i ++) {
            int old_buy = buy;
            buy = max(sold - prices[i], buy);
            
            sold = max(old_buy + prices[i] - fee, sold);
        }
        return sold;

    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
