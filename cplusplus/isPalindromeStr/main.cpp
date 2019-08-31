//
//  main.cpp
//  isPalindromeStr
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() < 2) {
            return true;
        }
        transform(s.begin(),s.end(),s.begin(),::tolower);
        
        cout << s <<endl;
        int start = 0;
        int end = s.size() - 1;
        
        while (start < end) {
            while (not isalpha(s[start]) and not isdigit(s[start]))
            {
                start += 1;
                if (start > end)
                {
                    break;
                }
            }
            while (not isalpha(s[end]) and not isdigit(s[end]))
            {
                end -= 1;
                if (start > end)
                {
                    break;
                }
            }
            cout << start << " " << end << endl;
            if (start > end)
            {
                break;
            }
            
            if (s[start] == s[end]) {
                start += 1;
                end -= 1;
            }
            else
            {
                return false;
            }
            
        }
        return true;
    }
    
    bool isPalindrome2(string s)
    {
        string tmp = "";
        int i;
        for(i = 0; i < s.length(); i++)
        {
            if(islower(s[i]) || isdigit(s[i]))
            {
                tmp += s[i];
            }
            else if(isupper(s[i]))
            {
                tmp += tolower(s[i]);
            }
        }
        int j = tmp.length() - 1;
        i = 0;
        while(i < j)
        {
            if(tmp[i] != tmp[j])
                return false;
            i ++;
            j -- ;
        }
        return true;
    }
    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    string input = "A man, a plan, a canal: Panama";
    input = "0P";
    bool res = s.isPalindrome(input);
    cout << res << endl;
    
    
    return 0;
}
