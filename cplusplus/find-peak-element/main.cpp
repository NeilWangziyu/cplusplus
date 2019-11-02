//
//  main.cpp
//  find-peak-element
//
//  Created by 王子昱 on 2019/10/21.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return 0;
        }
        
        int size = nums.size();
        int low = 0;
        int high = size-1;
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            // cout << mid;
            if(mid == 0)
            {
                if(nums[mid+1] < nums[mid])
                    return mid;
                else
                    low = mid + 1;
            }
            else if(mid == size - 1)
                
            {
                if(nums[mid - 1] < nums[mid])
                    return mid;
                else
                    high = mid - 1;
            }
            else
            {
                if(nums[mid - 1] < nums[mid] and nums[mid + 1] < nums[mid])
                    return mid;
                else
                {
                    if(nums[mid-1] > nums[mid + 1])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
            }
        }
        return low + (high - low) / 2;
        
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
