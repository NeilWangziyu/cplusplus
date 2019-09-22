//
//  main.cpp
//  minPathSum
//
//  Created by 王子昱 on 2019/9/19.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    
         int row = grid.size();
         int col = grid[0].size();


         for (int i = 1; i < row; i ++) {
             grid[0][i] = grid[0][i] + grid[0][i-1];
         }

         for (int i = 1; i < col; i ++) {
             grid[i][0] = grid[i][0] + grid[i-1][0];
         }

         for (int i = 1; i < col; i ++) {
             for (int j = 1; j < row; j ++) {
                 grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
             }
         }
         return grid[row-1][col-1];
        
    }
};

//int n= grid[0].size();
//int m= grid.size();
//for(int i=1;i<n;i++) grid[0][i]=grid[0][i-1]+ grid[0][i];
//for(int i=1;i<m;i++) grid[i][0]=grid[i-1][0]+ grid[i][0];
//for(int i=1;i<m;i++)
//{
//    for(int j=1;j<n;j++)
//    {
//        grid[i][j]=min(grid[i-1][j]+grid[i][j],grid[i][j-1]+grid[i][j]) ;
//    }
//}
//return grid[m-1][n-1];


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    return 0;
}
