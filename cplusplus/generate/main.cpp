//
//  main.cpp
//  generate
//
//  Created by 王子昱 on 2019/7/16.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0)
            return res;
        
        vector<int> first_row = {1};
        res.push_back(first_row);
        int c = 0;
        while(c < numRows - 1)
        {
            vector<int> next_row;
            next_row.push_back(1);
            for(int i = 1; i <c+1; i++)
            {
                next_row.push_back(res[c][i] + res[c][i-1]);
            }
            next_row.push_back(1);
            res.push_back(next_row);
            c += 1;
        }
        return res;
        
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    int num = 10;
    vector<vector<int>> res = s.generate(num);
    
    return 0;
}
