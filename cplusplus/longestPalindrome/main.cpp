//
//  main.cpp
//  longestPalindrome
//
//  Created by 王子昱 on 2019/9/12.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome0(string s) {
//        dont very understand
        const int n = s.size();
        
        if (n == 0 || n == 1) {
            return s;
        }
        
        int k = 0;
        int e = 0;
        int dp[n];
        
        for (int j = 0; j < n; j ++) {
            for (int i =0 ; i< j; i++) {
                if (!(dp[i] == dp[i+1] || s[i] != s[j]) && (e - k) <= (j - i)) {
                    k = i, e = j;
                }
            }
        }
        
        return s.substr(k, e - k + 1);
    }
    
    string longestPalindrome(string s)
    {
        int len = s.size();
        if (len == 0 || len == 1) {
            return s;
        }
        
        int start = 0;
        int max = 1;
        vector<vector<int>> dp(len, vector<int>(len));
        
        
        for (int i = 0; i < len; i ++) {
            dp[i][i] = 1;
            if (i < len - 1 && s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                max = 2;
                start = i;
            }
        }
        
        for (int l = 3; l <= len; l++) {
            for (int i = 0; i + l - 1 < len; i++) {
                int j = l + i - 1;
                if (s[i] == s[j] && dp[i+1][j-1] == 1) {
                    dp[i][j] = 1;
                    start = i;
                    max = l;
                }
            }
        }
        return s.substr(start, max);
    }
    
    string longestPalindrome2(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//记录回文子串起始位置
        int end=0;//记录回文子串终止位置
        int mlen=0;//记录最大回文子串的长度
        for(int i=0;i<len;i++)
        {
            int len1=expendaroundcenter(s,i,i);//一个元素为中心
            int len2=expendaroundcenter(s,i,i+1);//两个元素为中心
            mlen=max(max(len1,len2),mlen);
            if(mlen>end-start+1)
            {
                start=i-(mlen-1)/2;
                end=i+mlen/2;
            }
        }
        return s.substr(start,mlen);
        //该函数的意思是获取从start开始长度为mlen长度的字符串
    }

private:
    int expendaroundcenter(string s,int left,int right)
    //计算以left和right为中心的回文串长度
    {
        int L=left;
        int R=right;
        while(L>=0 && R<s.length() && s[R]==s[L])
        {
            L--;
            R++;
        }
        return R-L-1;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    string input = "xabayab";
    string output = s.longestPalindrome0(input);
    cout << output << endl;
    
    output = s.longestPalindrome2(input);
    cout << output << endl;

    output = s.longestPalindrome(input);
    cout << output << endl;
    
    return 0;
}
