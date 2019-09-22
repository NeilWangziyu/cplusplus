//
//  main.cpp
//  addBinary
//
//  Created by 王子昱 on 2019/9/19.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        while (a.size() != b.size()) {
            if (a.size() > b.size()) {
                b = "0" + b;
            }
            else
                a = "0" + a;
            
        }

        for (int i = a.size() - 1; i > 0; i--) {
            a[i] = a[i] - '0' + b[i];
            if (a[i] > '1') {
                a[i] = (a[i] - '0') % 2 + '0';
                a[i-1] = a[i-1] + 1;
            }
        }
        a[0] = a[0] - '0' + b[0];
        if (a[0] > '1') {
            a[0] = (a[0] - '0') % 2 + '0';
            a = '1' + a;
        }
        return a;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    string s1 = "11";
    string s2 = "1";
    string out = s.addBinary(s1, s2);
    cout << out << endl;
    
    
    return 0;
}
