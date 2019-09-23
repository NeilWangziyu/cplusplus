//
//  main.cpp
//  merge-intervals
//
//  Created by 王子昱 on 2019/9/22.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool func(const vector<int>a, const vector<int>b)
    {
        //        从小到大排序
        if (a[1] < b[1] ) {
            return true;
        }
        else if(a[1] > b[1])
            return false;
        else
        {
            return a[0] <= b[0] ? true:false;
        }
    }
    
    
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        vector<vector<int>> res;
//
//        if (intervals.size() <= 1) {
//            return intervals;
//        }
//
//        //        sort(intervals.begin(), intervals.end(), func);
//        sort(intervals.begin(), intervals.end());
//        vector<int> check(2,0);
//        for (auto now:intervals) {
//            if (check[0] == 0 and check[1] == 0) {
//                check =now;
//            }
//            else{
//                if (now[0] > check[1]) {
//                    res.push_back(check);
//                    check = now;
//                }
//                else
//                {
//                    check[0] = min(check[0], now[0]);
//                    check[1] = max(check[1], now[1]);
//                }
//            }
//        }
//        res.push_back(check);
//        return res;
//    }
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans{intervals[0]};
        int n = intervals.size();
        for(int i = 0; i < n; i ++){
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
                continue;
            }
            else{
                ans.push_back(intervals[i]);
                continue;
            }
        }
        return ans;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
