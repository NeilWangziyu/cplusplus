//
//  main.cpp
//  maxSlidingWindow
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct item{
public:
    int index;
    int value;
    item(int i, int v): index(i), value(v){};
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0)
        {
            return vector<int> {};
        }
        if(k == 1)
        {
            return nums;
        }
        vector<item> stack;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (stack.size()==0)
            {
                stack.push_back(item(i, nums[i]));
            }
            else
            {
                item new_item(i, nums[i]);
                while (stack.size() > 0 and stack.back().value < new_item.value) {
                    stack.pop_back();
                }
                stack.push_back(new_item);
                
                while (stack.front().index <= i - k) {
                    stack.erase(stack.begin());
                }
                
                if (i >= k-1) {
                    res.push_back(stack.front().value);
                }
                
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = s.maxSlidingWindow(nums, k);
    
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}
