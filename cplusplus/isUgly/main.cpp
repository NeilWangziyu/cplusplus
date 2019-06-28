//
//  main.cpp
//  isUgly
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
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }
        
        while (num % 3 == 0) {
            num /= 3;
        }
        
        while (num % 2 == 0) {
            num /= 2;
        }
        while (num % 5 == 0) {
            num /= 5;
        }
        return num == 1 ? true : false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    
    bool res = s.isUgly(100);
    cout << res << endl;
    res = s.isUgly(6);
    cout << res << endl;

    res = s.isUgly(8);
    cout << res << endl;
    
    res = s.isUgly(14);
    cout << res << endl;
    
    return 0;
}
