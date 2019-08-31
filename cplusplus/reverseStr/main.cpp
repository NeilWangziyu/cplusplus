//
//  main.cpp
//  reverseStr
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n ; i += 2 * k)
        {
            int begin = i;
            int end = i + k -1 > n - 1? n-1:i+k-1;
            reverse(s, begin, end);
        }
        return s;
    }
    
    
    void reverse(string &s, int start, int end)
    {
        for(int i = start, j = end; i<j;i++,j--)
        {
            swap(s[i], s[j]);
        }
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    string s1 = "abcdefg";
    int k = 2;
    string res = s.reverseStr(s1, k);
    cout << res << '\n';
    return 0;
}
