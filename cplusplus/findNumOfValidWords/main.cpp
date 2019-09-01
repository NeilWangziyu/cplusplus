//
//  main.cpp
//  findNumOfValidWords
//
//  Created by 王子昱 on 2019/9/1.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
//    没看懂根本就...
public:
    map<int,int> a;
    vector<int> ans;
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        a.clear();
        int n=words.size(),m=puzzles.size(),i,j,k;
        ans.resize(m,0);
        for(i=0;i<n;i++)
        {
            for(j=k=0;j<words[i].size();j++)k|=1<<words[i][j]-'a';
            a[k]++;
        }
        for(i=0;i<m;i++)
        {
            for(j=k=0;j<puzzles[i].size();j++)k|=1<<puzzles[i][j]-'a';
            for(j=k;j;j=j-1&k)if(j>>puzzles[i][0]-'a'&1)ans[i]+=a[j];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
