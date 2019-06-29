//
//  main.cpp
//  lengthOfLastWord
//
//  Created by 王子昱 on 2019/6/29.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::map;
using std::set_intersection;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = 0;
        int tem = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == ' '){
                if (c != 0) tem = c;
                c = 0;
            }
            else if(s[i] == '\0') break;
            
            else{
                c += 1;
            }
                    }
        return c == 0 ? tem:c;
    }
    
    int lengthOfLastWord2(string s) {
        int begin=0;
        int n=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==' ' && s[begin]!=' ')
            {
                n = i-begin;
                begin = i;
            }
            if(s[begin]==' ')
                begin++;
            if(i==s.size()-1 && s[i]!=' ')
                n=i-begin+1;
        }
        return n;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    int res = s.lengthOfLastWord("a ");
    cout << res << endl;
    
    res = s.lengthOfLastWord("Hello worldlong  t");
    cout << res << endl;

    return 0;
}
