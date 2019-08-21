//
//  main.cpp
//  removeElement
//
//  Created by 王子昱 on 2019/8/21.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        if (nums.size()==0) {
            return 0;
        }
        int p1 = 0;
        while (p1 < nums.size() and nums[p1] != val) {
            p1 += 1;
        }
        
        if (p1 == nums.size()){
            return p1;
        }
        int p2 = p1;
        
        while (p2 < nums.size()) {
            if (nums[p2] == val) {
                p2 += 1;
            }
            else{
                int tem = nums[p2];
                nums[p2] = nums[p1];
                nums[p1] = tem;
                p2 += 1;
                p1 += 1;
            }
        }
        return p1;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    vector<int> nums = {3,2,2,3};
    vector<int> & input = nums;
    int val = 3;
    int ouput = s.removeElement(input, val);
    cout << "out:" << ouput << endl;
    for (int i = 0; i < ouput; ++i) {
        cout << nums[i] << endl;
        
    }
    return 0;
}
