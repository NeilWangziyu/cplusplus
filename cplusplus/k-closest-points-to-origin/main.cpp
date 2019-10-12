//
//  main.cpp
//  k-closest-points-to-origin
//
//  Created by 王子昱 on 2019/10/12.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<int> anchor = points[0];
        
        vector<vector<int>> less;
        vector<vector<int>> more;
        

        int anchor_len = anchor[0] * anchor[0] + anchor[1] * anchor[1];
        
        for(int i = 1; i < points.size(); i++)
        {
            vector<int> tem_check = points[i];
            int tem = tem_check[0] * tem_check[0] + tem_check[1] * tem_check[1];
//            cout << "tem " << tem << endl;
            if(tem >= anchor_len)
            {
                more.push_back(tem_check);
            }
            else
                less.push_back(tem_check);
        }
        
        if(less.size() == K)
        {
            return less;
        }
        else if(less.size() == K - 1)
        {
            less.push_back(anchor);
            return less;
        }
        else if(less.size() < K)
        {
            less.push_back(anchor);
            int less_size = less.size();
            vector<vector<int>> left = kClosest(more, K - less_size);
            less.insert(less.end(), left.begin(), left.end());
            return less;
        }
        else
//             less.size() > K
            return  kClosest(less, K);
        
        
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    
    vector<vector<int>> points;
    vector<int> a = {3,3};
    vector<int> b = {5,-1};
    vector<int> c = {-2,4};
    int K = 2;

    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    
    vector<vector<int>> res =s.kClosest(points,K);
    
    for (auto each:res) {
        for (int n:each) {
            cout << n << " ";
        }
        cout << endl;
    }
    
    return 0;
}
