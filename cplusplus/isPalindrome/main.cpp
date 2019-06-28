//
//  main.cpp
//  isPalindrome
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
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        if (x < 10) {
            return true;
        }
        
        int nums = 0;
        int temp = x;
        int left, right;
        while (temp != 0) {
            temp /= 10;
            nums ++;
        }
        left = nums - 1;
        right = 0;
        
        while (left > right) {
            if (getDigit(x, left--) != getDigit(x, right++)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isPalindrome2(int x) {
        int a = x, b;
        int i = -1, j = 0;
        int arry[100];
//        cout << a << endl;
        if(a<0)
        {
            return false;
        }
        else
        {
            while(a!=0)
            {
                i++;
                b=a%10;
                a=a/10;
                arry[i]=b;
            }
            
            while(j<i)
            {
                if(arry[j++]==arry[i--])
                    continue;
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    
    
private:
    int getDigit(int x, int i)
        {
            x = x / (int)pow(10, i);
            return x % 10;
        }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    
    bool res = s.isPalindrome(1000);
    cout << res <<endl;
    
    res = s.isPalindrome(999);
    cout << res <<endl;
    
    
    res = s.isPalindrome2(1000);
    cout << res <<endl;
    
    res = s.isPalindrome2(999);
    cout << res <<endl;
    return 0;
}
