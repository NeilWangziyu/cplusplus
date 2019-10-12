//
//  main.cpp
//  escape-the-ghosts
//
//  Created by 王子昱 on 2019/10/12.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int our_size = abs(target[0])+abs(target[1]);
        int ghost_len = INT_MAX;
        for(int i= 0; i < ghosts.size(); i++)
        {   vector<int> check = ghosts[i];
            ghost_len = min(ghost_len, abs(check[0]-target[0])+abs(check[1]-target[1]));
        }
        return our_size < ghost_len ? true : false;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
