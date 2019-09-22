//
//  main.cpp
//  nextPermutation
//
//  Created by 王子昱 on 2019/9/19.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) {
            return ;
        }
        int i = nums.size() - 2;
        while (i >= 0 and nums[i] >= nums[i+1]) {
            i -= 1;
        }
        if (i < 0) {
            sort(nums.begin(), nums.end());
            return ;
        }
        int k = nums.size() - 1;
        while (k > i and nums[k] <= nums[i]) {
            k -= 1;
        }
        
        int tem = nums[i];
        nums[i] = nums[k];
        nums[k] = tem;
        sort(nums.begin()+i+1, nums.end());
        return ;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    vector<int> input = {3,2,1};
    vector<int> &in = input;
    s.nextPermutation(in);
    for (auto item:input) {
        cout << item << endl;
    }
    
    return 0;
}
