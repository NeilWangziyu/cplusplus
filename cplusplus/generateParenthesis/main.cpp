//
//  main.cpp
//  generateParenthesis
//
//  Created by 王子昱 on 2019/9/19.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return res;
        else
            Generate("", 0, 0, 2*n);
        return res;
            
    }
    
    void Generate(string t, int used, int unfill, int n)
    {
        if (unfill < 0) {
            return ;
        }
        
        if (used == n) {
            if (unfill == 0) {
                res.push_back(t);
            }
            return;
        }

        Generate(t + "(", used+1, unfill+1, n);
        Generate(t + ")", used+1, unfill-1, n);
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    int input = 3;
    vector<string> res = s.generateParenthesis(input);
    for (auto t:res) {
        cout << t << endl;
    }
    
    return 0;
}
