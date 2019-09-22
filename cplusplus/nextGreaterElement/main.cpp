//
//  main.cpp
//  nextGreaterElement
//
//  Created by 王子昱 on 2019/9/22.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:

    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> nums_larger_map;
        for (int i = nums2.size()-1 ; i >= 0; i --) {
            if (i == nums2.size() - 1) {
                nums_larger_map[nums2[i]] = -1;
            }
            else
            {
                for (int j = i + 1; j < nums2.size(); j ++) {
                    if (nums2[j] > nums2[i]) {
                        nums_larger_map[nums2[i]] = nums2[j];
                        break;
                    }
                }
                if (nums_larger_map.find(nums2[i]) == nums_larger_map.end()) {
                    nums_larger_map[nums2[i]] = -1;
                }
            }
        }
        
        vector<int> res;
        for (auto item:nums1) {
            res.push_back(nums_larger_map[item]);
        }
        return res;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
