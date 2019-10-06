//
//  main.cpp
//  largest-sum-of-averages
//
//  Created by 王子昱 on 2019/9/28.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if (A.size() == 0) {
            return 0;
        }
        if (A.size() == 1) {
            return A[0];
        }
        /**
       dp[i][k]表示前i个数构成k个子数组时的最大平均值, 那么对于所有 0 <= j <= i-1
       dp[i][k] = Math.max(dp[i][k], dp[j][k-1] + (A[j+1] + ... + A[i+1]) / (i-j))
         **/
        vector<vector<double>> dp(A.size()+1, vector<double>(K+1, 0));
        vector<double> sum_of_num(A.size()+1, 0);
        
        for (int i = 1; i < A.size()+1; i++) {
            sum_of_num[i] = A[i-1] + sum_of_num[i-1];
            dp[i][1] = sum_of_num[i] / i;
        }
        
        for (int i = 0 ; i <= A.size(); i++) {
            for (int k = 2; k <= K; k++) {
                for (int j = 0; j < i; j++) {
                    dp[i][k] = max(dp[i][k], dp[j][k-1] + (sum_of_num[i] - sum_of_num[j])/(i-j));
                }
            }
        }
//        for (auto item:dp) {
//            for (auto each_item:item) {
//                cout << each_item << " ";
//            }
//            cout << endl;
//        }
        return dp[A.size()][K];
        
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    vector<int> A = {9,1,2,3,9};
    int k = 3;
    int res = s.largestSumOfAverages(A, k);
    cout << res << endl;
    
    return 0;
}
