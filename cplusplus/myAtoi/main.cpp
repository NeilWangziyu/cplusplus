//
//  main.cpp
//  myAtoi
//
//  Created by 王子昱 on 2019/9/19.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(isalpha(str[0])) return 0;
        bool flag = true;
//        true means positive
        long long ans = 0;
        int count = 0;
        int tem = 0;
        for (auto t : str) {
            if ((t == '+' || t == '-' ) && count==0) {
                flag = (t == '+')?true:false;
                tem += 1;
            }
            else if (0<=(t-'0') && (t-'0')<=9 && tem<2)
            {
                ans = ans * 10 + t - '0';
                count += 1;
                if(ans-1>INT_MAX) break;
            }else if(t==' ' && count == 0 && tem ==0)
                //如果是空格则继续 但前提是 之前没有出现过 正负号 和 数字
                continue;
            else        //其他情况：英文和其他字符
                break;

        }
        if (flag == false) {
            return -ans<INT_MIN? INT_MIN:-ans;
        }else
            return ans > INT_MAX?INT_MAX:ans;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
