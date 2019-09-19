//
//  main.cpp
//  threeSum
//
//  Created by 王子昱 on 2019/9/19.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum0(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) {
            return res;
        }
        
        sort(nums.begin(), nums.end());
        map<string, string> checkedmap;
        
        for (int i =0; i < nums.size(); i++) {
            int first_num = nums[i];
            int target = -first_num;
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back) {
                if(nums[front] + nums[back] == target)
                {
                    // cout << nums[front] << nums[back] << target <<endl;
                    string tem = to_string(first_num) + to_string(nums[front]) + to_string(nums[back]);
                    if (checkedmap.find(tem) == checkedmap.end()) {
                        checkedmap[tem] = tem;
                        vector<int> tem_vector = {first_num, nums[front], nums[back]};
                        res.push_back(tem_vector);
                    }
                    front += 1;
                    back -= 1;
                }
                else if(nums[front] + nums[back] > target)
                {
                    back -= 1;
                }
                else
                    front += 1;
            }
        }
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) {
            return res;
        }
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        
        while(i < nums.size()) {
            int first_num = nums[i];
            int target = -first_num;
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back) {
                if(nums[front] + nums[back] == target)
                {
                    while (front < nums.size()-1 && nums[front+1] == nums[front]) {
                        front += 1;
                    }
                    while (back > 0 && nums[back-1] == nums[back]) {
                        back -= 1;
                    }
                    vector<int> tem_vector = {first_num, nums[front], nums[back]};
                    // for (auto each:tem_vector) {
                    //     cout << each << endl;
                    // }
                    res.push_back(tem_vector);
                    front += 1;
                    back -= 1;
                }
                else if(nums[front] + nums[back] > target)
                {
                    back -= 1;
                }
                else
                {front += 1;}
                
            }
            i += 1;
            while(i < nums.size() && nums[i] == nums[i-1])
            {
                i += 1;
            }
        }
        return res;
    }

};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    vector<int> input = {0,0,0,0,1,-1};
    vector<vector<int>> res = s.threeSum(input);
    return 0;
}
