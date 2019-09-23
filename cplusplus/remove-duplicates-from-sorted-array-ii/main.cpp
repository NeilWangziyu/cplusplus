//
//  main.cpp
//  remove-duplicates-from-sorted-array-ii
//
//  Created by 王子昱 on 2019/9/23.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <=2 ) {
            return int(nums.size());
        }
        int i = 1;
        int j = 0;
        int c = 1;
        int prev = nums[0];
        
        while (i < nums.size()) {
            if (nums[i] == prev) {
                c += 1;
            }
            else
            {
                for (int t = 0; t < min(c, 2); t++) {
                    nums[j] = prev;
                    j += 1;
                }
                c = 1;
                prev = nums[i];
            }
            i += 1;
        }
        for (int t = 0; t < min(c, 2); t++) {
            nums[j] = prev;
            j += 1;
        }
        return j;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    vector<int> nums={1,1,1,2,2,3};
    int res = s.removeDuplicates(nums);
    cout << res << endl;
    for (auto item:nums) {
        cout << item << endl;
    }
    return 0;
}
