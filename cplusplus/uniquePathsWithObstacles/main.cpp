//
//  main.cpp
//  uniquePathsWithObstacles
//
//  Created by 王子昱 on 2019/9/19.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<long>> dp(m, vector<long>(n,0));
        
        for (int i = 0; i < n; i ++) {
            if (obstacleGrid[0][i] == 0) {
                dp[0][i] = 1;
            }
            else
                break;
        }
        for (int j= 0; j < m; j++) {
            if (obstacleGrid[j][0] == 0) {
                dp[j][0] = 1;
            }
            else
                break;
        }
        
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else
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
    vector<vector<int>> input(4, vector<int>(5,0));
    input[0][1] = 1;
    input[1][0] = 1;
    int res = s.uniquePathsWithObstacles(input);
    cout << res << endl;
    
    return 0;
}
