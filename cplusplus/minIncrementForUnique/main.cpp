//
//  main.cpp
//  minIncrementForUnique
//
//  Created by 王子昱 on 2019/9/10.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n[50000] = {0};
        int len = A.size();
        for (int i = 0; i < len; i ++) {
            n[A[i]] ++;
        }
        int move = 0;
        for (int i = 0; i < 50000; i ++) {
            if (n[i] <= 1) {
                continue;
            }
            move += n[i] - 1;
            n[i + 1] += n[i] -1;
            n[i]= 1;
        }
        return move;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    vector<int> input = {1,2,2,4,4,4,9};
    int res = s.minIncrementForUnique(input);
    cout << res;
    
    return 0;
}
