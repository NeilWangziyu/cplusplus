//
//  main.cpp
//  powerful-integers
//
//  Created by 王子昱 on 2019/10/9.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        set<int> checked;
        for(int i = 0; i < 20; i ++)
        {
            if(pow(x, i) > bound)
                break;
            
            for (int j = 0; j <= 20; j++)
            {
                int tem = pow(x, i) + pow(y, j);
                if(tem <= bound)
                {
                    if(checked.find(tem) == checked.end())
                    {
                        checked.insert(tem);
                        // res.push_back(pow(x, i) + pow(y, j));
                    }
                }
                else
                {
                    break;
                }
            }
        }
        for(int each:checked)
            res.push_back(each);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
