//
//  main.cpp
//  intersect
//
//  Created by 王子昱 on 2019/9/22.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            swap(nums1, nums2);
        }
        unordered_map<int, int> check_dict;
        for (auto item:nums1) {
            if (check_dict.find(item) != check_dict.end()) {
                check_dict[item] += 1;
            }
            else
                check_dict[item] = 1;
        }
        vector<int> res;
        for (auto item:nums2)
        {
            if (check_dict.find(item) != check_dict.end()) {
                if (check_dict[item] > 0) {
                    res.push_back(item);
                    check_dict[item] -= 1;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
