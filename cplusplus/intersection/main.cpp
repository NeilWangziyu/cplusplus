//
//  main.cpp
//  intersection
//
//  Created by 王子昱 on 2019/6/28.
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
    vector<int> intersection0(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>result;
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]<nums2[j])
                ++i;
            else if(nums1[i]>nums2[j])
                ++j;
            else
            {
                if(result.empty()||result[result.size()-1]!=nums1[i])
                    result.push_back(nums1[i]);
                ++i;
                ++j;
            }
        }
        return result;
    }
    
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        
//        标准库提供了 std::set_intersection 和 std::set_union 两个函数，用于对容器内的元素进行集合求交、求并，而后将得到的结果保存在 OutputIt 对应的容器当中。
        
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        vector<int> res;
        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(res));
        return res;
    }
    
    
    
    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> temp;
        for(auto it:nums1)
        {
            temp[it]++;
        }
        for(auto it:nums2)
        {
            if(temp.count(it)!=0)
            {
                res.push_back(it);
                temp.erase(it);
            }
        }
        return res;
    }
    
    vector<int> intersection3(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> temp;
        for(auto it:nums1)
        {
            temp[it]++;
        }
        for(auto it:nums2)
        {
            if(temp.count(it)!=0)
            {
                res.push_back(it);
                temp.erase(it);
            }
        }
        return res;
    }
    
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        非常奇怪为何在leetcode上面无法运行
        map<int, char> hash;
        vector<int> res;
        
        for (int i = 0; i <= nums1.size(); ++i) {
            if (hash.find(nums1[i]) == hash.end()){
                hash.insert(pair<int, char>(nums1[i], 't'));
            }
        }
        
        for (int j=0; j<=nums2.size(); ++j) {
            
            if (hash.find(nums2[j])!=hash.end()) {
                if (hash[nums2[j]] == 't'){
//                    cout << j <<  hash[nums2[j]] << endl;
                    res.push_back(nums2[j]);
                    hash[nums2[j]] = 'f';
                }
            }
        }
        return res;
    }

    
};

    


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> nums1 = {1,2,2,1,3,4,5,6};
    vector<int> nums2 = {2,2,5,6};
    
    cout << nums1.size()<<endl;
    
    for (int t = 0; t < nums1.size(); ++t) {
        
        cout << t << " " << nums1[t] << endl;
    }
    cout << endl;
    
    Solution s;
    vector<int> res = s.intersection2(nums1, nums2);
    cout << "length " << res.size() <<endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    
    res = s.intersection(nums1, nums2);

    cout << "length " << res.size() <<endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
    
    
}
