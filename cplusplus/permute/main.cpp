//
//  main.cpp
//  permute
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return res;
        }
        
        return permute_core(nums);
    }
    
    vector<vector<int>> permute_core(vector<int>& nums)
    {
        vector<vector<int>> r;
        if(nums.size() == 0)
        {
            return r;
        }
        else if (nums.size() == 1)
        {
            r.push_back(vector<int>{nums[0]});
            return r;
        }
        else
        {
            for (int i = 0; i < nums.size(); i++) {
                vector<int> separate = {nums[i]};
                vector<int> left;
                for (int j = 0; j < nums.size(); j ++) {
                    if (j != i) {
                        left.push_back(nums[j]);
                    }
                }
                
                vector<vector<int>> left_result = permute_core(left);
                for (auto each_res : left_result) {
                    vector<int> new_r;
                    new_r.insert(new_r.end(), separate.begin(), separate.end());
                    new_r.insert(new_r.end(), each_res.begin(), each_res.end());
                    r.push_back(new_r);
                }
            }
            return r;

        }
        
    }
};

class Solution2 {
//    回溯法
public:
    vector<vector<int>> res;
    
    vector<vector<int>> permute(vector<int>& nums)
    {
        backtrack(nums,0);
        return res;
    }
    void swap(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    void backtrack(vector<int> &nums,int i)
    {
        if(i==nums.size())
            res.push_back(nums);
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            backtrack(nums,i+1);
            swap(nums[i],nums[j]);//回溯
        }
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    Solution2 s2;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = s.permute(nums);
    for (auto each_line : res) {
        for (auto each : each_line)
        {
            std::cout << each << " ";
        }
        std::cout << "\n";

    }
    res = s2.permute(nums);
    std::cout << "s2:" << endl;
    for (auto each_line : res) {
        for (auto each : each_line)
        {
            std::cout << each << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
