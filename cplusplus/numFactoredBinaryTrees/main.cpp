//
//  main.cpp
//  numFactoredBinaryTrees
//
//  Created by 王子昱 on 2019/9/10.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        unordered_map<int, long> hash, dp;
        for (auto &i: A) {
            ++hash[i];
            dp[i] = 1;
        }
        sort(A.begin(), A.end());
        long mod = pow(10, 9) + 7;
        long sum = 0;
        for (int k = 0; k < A.size(); k++) {
            int cur = A[k];
            for (int j = 0; j < k; j ++) {
                if (cur % A[j] == 0 && hash[cur / A[j]]) {
                    dp[cur] = dp[cur] + dp[A[j]] * dp[cur/A[j]];
                }
            }
            sum = (sum + dp[cur]) % mod;
        }
        return sum;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::vector<int> input = {2,4,5,10};
    Solution s;
    
    int res = s.numFactoredBinaryTrees(input);
    cout << res << endl;
    return 0;
}
