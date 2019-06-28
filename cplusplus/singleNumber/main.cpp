//
//  main.cpp
//  singleNumber
//
//  Created by 王子昱 on 2019/6/28.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
using std::cout;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto it:nums) {
            res = res ^ it;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    vector<int> v = {9,9,1,1,7};
    int res = s.singleNumber(v);
    cout << res <<endl;
    
    return 0;
}
