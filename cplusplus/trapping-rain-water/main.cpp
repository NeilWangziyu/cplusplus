//
//  main.cpp
//  trapping-rain-water
//
//  Created by 王子昱 on 2019/9/23.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int lenth = height.size();
        vector<int> left(lenth, 0);
        vector<int> right(lenth,0);
        int left_max = -1;
        int right_max = -1;
        for (int i = 0; i < height.size(); i++) {
            left_max = max(height[i], left_max);
            left[i] = left_max;
        }
        
        for (int j = lenth - 1; j >= 0; j--) {
            right_max = max(right_max, height[j]);
            right[j] = right_max;
        }
        
        int res = 0;
        for (int t = 0; t < lenth; t++) {
            res += min(left[t], right[t]) - height[t];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
