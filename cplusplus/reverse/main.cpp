//
//  main.cpp
//  reverse
//
//  Created by 王子昱 on 2019/6/28.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

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
    int reverse(int x) {
        int res = 0;
        while( x != 0)
        {
            if (abs(res) > INT_MAX /10 ) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
        
    }
    
    int reverse2(int x) {
        int flag=1;
        long long back=0;
        if(-2147483648==x)
            return 0;
        if(x<0)
        {
            flag=-1;
            x=x*flag;
        }
        for(int i=0;x>0;i++)
        {
            back=10*back+x%10;
            if(back>2147483647)
            {
                back=0;
                break;
            }
            
            x=x/10;
            
        }
        back=back*flag;
        return back;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    
    int x = 1100;
    
    int res = s.reverse(x);
    cout << res <<endl;
    
    int res2 = s.reverse2(x);
    cout << res2 << endl;
    
    
    return 0;
    
}
