//
//  main.cpp
//  intToRoman
//
//  Created by 王子昱 on 2019/9/16.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        map<int,string> mapRom = {{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"}, {90,"XC"},{100,"C"},                                              {400,"CD"},{500,"D"},{900,"CM"}, {1000,"M"} };
        map<int,string>::reverse_iterator  r_iter;
        
        string res;
        r_iter=mapRom.rbegin();
        
        while(r_iter!=mapRom.rend())
        {
            if(num >= r_iter->first)
            {
                res += r_iter->second;
                num -= r_iter->first;
            }
            else
            {
                r_iter ++;
            }
        }
        return res;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    int input = 1024;
    string output = s.intToRoman(input);
    cout << output << endl;
    
    return 0;
}
