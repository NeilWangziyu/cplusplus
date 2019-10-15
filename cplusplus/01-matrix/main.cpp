//
//  main.cpp
//  01-matrix
//
//  Created by 王子昱 on 2019/10/15.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> check_num;
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = row + col;
                }
                if (i > 0) {
                    matrix[i][j] = min(matrix[i][j], matrix[i-1][j] + 1);
                }
                if (j > 0) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][j - 1] + 1);
                }
            }
        }
        for (int i = row - 1; i >= 0; i --) {
            for (int j = col - 1; j >= 0; j -- ) {
                if (i < row - 1) {
                    matrix[i][j] = min(matrix[i][j], matrix[i+1][j] + 1);
                }
                if (j < col - 1) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][j+1] + 1);
                }
            }
        }
        return matrix;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
