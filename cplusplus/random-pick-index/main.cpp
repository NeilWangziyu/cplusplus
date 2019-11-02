//
//  main.cpp
//  random-pick-index
//
//  Created by 王子昱 on 2019/10/21.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(check_map.find(nums[i]) == check_map.end())
            {
                check_map[nums[i]] = {i};
            }
            else
            {
                check_map[nums[i]].push_back(i);
            }
        }
        
    }
    
    int pick(int target) {
        int size = check_map[target].size();
        int index = rand() % size;
        return check_map[target][index];
        
    }
    
private:
    map<int, vector<int>> check_map;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
