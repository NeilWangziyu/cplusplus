//
//  main.cpp
//  maxArea
//
//  Created by 王子昱 on 2019/9/16.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1)
            return -1;
        
        int res = 0;
        int l = 0;
        int r = height.size()-1;
        while (l < r) {
            res = max(res, min(height[l], height[r])*(r-l));
            if (height[l] >= height[r]) {
                r -= 1;
            }
            else
                l += 1;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    vector<int> input = {1,8,6,2,5,4,8,3,7};
    int res = s.maxArea(input);
    cout << res;
    
    return 0;
}
