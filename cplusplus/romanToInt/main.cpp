//
//  main.cpp
//  romanToInt
//
//  Created by 王子昱 on 2019/9/16.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//Note: string substr(int pos = 0,int n = npos) const;//返回pos开始的n个字符组成的字符串
//substr 后面的数字，代表这个string长度是多少，而不是切片

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> ROMAN = {
            {"I",1},
            {"IV",4},
            {"V",5},
            {"IX",9},
            {"X",10},
            {"XL",40},
            {"L",50},
            {"XC",90},
            {"C",100},
            {"CD",400},
            {"D",500},
            {"CM",900},
            {"M",1000},
        };
        int res = 0;
        for (int i = 0; i < s.size();) {
            if (i + 1 < s.size() and ROMAN.find(s.substr(i, 2)) != ROMAN.end()) {
//                cout <<s.substr(i, 2) << endl;
                res += ROMAN[s.substr(i, 2)];
                i += 2;
            }
            else
            {
                res += ROMAN[s.substr(i, 1)];
//                cout <<s.substr(i, 1) << endl;
                i += 1;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    string input = "III";
    int output = s.romanToInt(input);
    cout << output << endl;
    
    input = "IV";
    output = s.romanToInt(input);
    cout << output << endl;
    
    input = "LVIII";
    output = s.romanToInt(input);
    cout << output << endl;
    
    return 0;
}
