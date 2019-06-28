//
//  main.cpp
//  twoSum
//
//  Created by 王子昱 on 2019/6/28.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (target == nums[i] + nums[j]) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;

    }
    
    vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            int surplus = target - nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                if (surplus == nums[j]) {
                    result.push_back(i);
                    result.push_back(j);
                    cout << result[0] <<  result[1] << endl;
                    return result;
                }
            }
        }
        
        return result;
    }
    
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    vector<int> nums = {2,7, 11, 15};
    int target = 9;
    
    vector<int> res = s.twoSum(nums, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    
    
    vector<int> res2 = s.twoSum2(nums, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    
    return 0;
}
