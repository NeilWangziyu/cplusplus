//
//  main.cpp
//  fourSum
//
//  Created by 王子昱 on 2019/9/16.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        
        sort(nums.begin(), nums.end());
        set<vector<int>> set_res;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size()-3; i ++) {
            for (int j = i + 1; j < nums.size()-2; j ++) {
                int l = j + 1;
                int r = nums.size() - 1;
                
                while (l < r) {
                    int tem_sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (tem_sum > target)
                    {
                        r -= 1;
                    }
                    else if(tem_sum < target)
                    {
                        l += 1;
                    }
                    else
                    {
                        vector<int> tem_vect = {nums[i], nums[j], nums[l], nums[r]};
                        set_res.insert(tem_vect);
                        l += 1;
                        r -= 1;
                    }
                    
                }
                
            }
            
        }
        for(auto c:set_res)
        {
            res.push_back(c);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    vector<int> input = {1,2,3,4,5,6,7,8,9,0, -1, -2, -3};
    
    vector<vector<int>> res = s.fourSum(input, 3);
    
    
    return 0;
}
