//
//  main.cpp
//  toLowerCase2
//
//  Created by 王子昱 on 2019/8/21.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        if (str == "") {
            return str;
        }
        string res = "";
        for (int i = 0; i < str.size(); i ++) {
            int ia = (int)str[i];
            if (ia >= 65 && ia <= 90) {
                ia += 32;
            }
            res += (char)ia;
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    string si = "PiTAs";
    string out = s.toLowerCase(si);
    cout << out << endl;
    
    return 0;
}
