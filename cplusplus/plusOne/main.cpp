//
//  main.cpp
//  plusOne
//
//  Created by 王子昱 on 2019/6/29.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::map;
using std::set_intersection;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if (digits[size-1] != 9){
            digits[size-1] += 1;
        }
        else{
            digits[size - 1] = 0;
            for (int i = size - 1; i > 0; -- i) {
                if (digits[i] == 0){
                    digits[i-1] = (digits[i-1] + 1) % 10;
                }
                else
                    break;
            }
            if (digits[0] == 0)
            {
                digits.insert(digits.begin(), 1);
            }
        }
        return digits;
        
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> v = {1,7,9};
    
    Solution s;
    
    vector<int> res  = s.plusOne(v);
    
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
