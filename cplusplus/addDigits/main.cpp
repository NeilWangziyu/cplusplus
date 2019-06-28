//
//  main.cpp
//  addDigits
//
//  Created by 王子昱 on 2019/6/28.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::map;

class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        while (num >= 10) {
            int res = 0;
            while (num >= 10) {
                res += num % 10;
                num /= 10;
            }
            res += num;
            num = res;
            cout << num <<endl;
        }
        return num;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    int res = s.addDigits(38);
    cout << res <<endl;
    
    
    
    return 0;
}
