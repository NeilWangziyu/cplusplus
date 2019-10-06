//
//  main.cpp
//  binary-subarrays-with-sum
//
//  Created by 王子昱 on 2019/10/6.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
//        not finish, over time
        if(A.size() == 0)
            return 0;
        
        vector<int> dp(A.size()+1, 0);
        
        for(int i = 0; i < A.size(); i++)
        {
            dp[i+1] = dp[i] + A[i];
        }
        
        int res = 0;
        for (int low = 0; low < dp.size()-1; low++) {
            for (int high = low + 1; high < dp.size(); high++) {
                int tem = dp[high] - dp[low];
                if (tem == S) {
                    res += 1;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
//    A = [1,0,1,0,1], S = 2
    int S = 2;
    vector<int> A = {1,0,1,0,1};
    
    int res = s.numSubarraysWithSum(A, S);
    cout << res << endl;
    
    
    return 0;
}
