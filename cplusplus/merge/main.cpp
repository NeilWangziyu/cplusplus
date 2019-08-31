//
//  main.cpp
//  merge
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
        {
            return;
        }
        
        if(m == 0)
        {
            for(int i=0; i < n; i++)
            {
                nums1[i] = nums2[i];
            }
            return;
        }
        
        int target = m + n - 1;
        while (m > 0 and n > 0) {
            if(nums1[m-1] > nums2[n-1])
            {
                nums1[target] = nums1[m-1];
                m -= 1;
                target -= 1;
            }
            else{
                nums1[target] = nums2[n-1];
                n -= 1;
                target -= 1;
            }
        }
        
        if(m == 0 and n == 0)
            return;
        else{
            if(m >0)
            {
                return;
            }
            else{
                while (n>0) {
                    nums1[target] = nums2[n-1];
                    n -= 1;
                    target -= 1;
                }
            }
        }
    }
    
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int len = m+n-1;
        int i=m-1;
        int j=n-1;
        
        while(i>=0&&j>=0)
        {
            if(nums1[i]>=nums2[j])
            {
                nums1[len]=nums1[i];
                i--;
                len--;
            }
            else
            {
                nums1[len]=nums2[j];
                len--;
                j--;
            }
        }
        while(j>=0)
        {
            nums1[len--]=nums2[j--];
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
