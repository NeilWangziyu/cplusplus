//
//  main.cpp
//  uniquePaths
//
//  Created by 王子昱 on 2019/9/19.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        for (int i = 0; i < n; i ++) {
            dp[0][i] = 1;
        }
        for (int j= 0; j < m; j++) {
            dp[j][0] = 1;
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    int re = s.uniquePaths(7,3);
    cout <<re << endl;
    
    return 0;
}
