//
//  main.cpp
//  relative-ranks
//
//  Created by 王子昱 on 2019/10/6.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int, string> check_maps;
        vector<int> nums_after_sort = nums;
        sort(nums_after_sort.begin(), nums_after_sort.end());
        reverse(nums_after_sort.begin(), nums_after_sort.end());
        for(int i = 0; i < nums_after_sort.size(); i++)
        {
            if(i == 0)
            {
                check_maps[nums_after_sort[i]] = "Gold Medal";
            }
            else if(i == 1)
            {
                check_maps[nums_after_sort[i]] = "Silver Medal";

            }
            else if(i == 2)
            {
                check_maps[nums_after_sort[i]] = "Bronze Medal";
            }
            else
                check_maps[nums_after_sort[i]] = to_string(i+1);
        }
        vector<string> res(nums.size());
        for(int index = 0; index < nums.size(); index++)
        {
            res[index] = check_maps[nums[index]];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
