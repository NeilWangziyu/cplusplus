//
//  main.cpp
//  combinationSum
//
//  Created by 王子昱 on 2019/9/10.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        if (candidates.size() == 0) {
            return res;
        }
        
        int value = 0;
        int start_num = 0;
        vector<int> tem;
        core(target, value, start_num, candidates, tem);
        return res;
        
    }
    
    void core(int & target,int & value, int & start_num, vector<int>& candidates, vector<int>& tem)
    {
        if (target < value) {
            return;
        }
        if(target == value)
        {
            res.push_back(tem);
        }
        if (start_num >= candidates.size()) {
            return ;
        }
        else
        {
            for (int i = start_num; i < candidates.size(); i += 1) {
                tem.push_back(candidates[i]);
                value += candidates[i];
                core(target, value, i, candidates, tem);
                tem.pop_back();
                value -= candidates[i];
            }
        }
    }

};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    int target = 7;
    vector<int> input = {2,3,6,7};
    vector<vector<int>> res = s.combinationSum(input, target);
    
    return 0;
}
