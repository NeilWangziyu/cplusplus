//
//  main.cpp
//  convert
//
//  Created by 王子昱 on 2019/9/12.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) {
            return s;
        }
        
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;
        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }
        string ret;
        for (string row : rows) {
            ret += row;
        }
        return ret;
    }
    
    string convert2(string s, int numRows) {
        if (numRows == 1) return s;
        
        int step = numRows * 2 - 2; // 间距
        int index = 0;// 记录s的下标
        int len = s.length();
        int add = 0; // 真实的间距
        string ret;
        for (int i = 0; i < numRows; i++) // i表示行号
        {
            index = i;
            add = i * 2;
            while (index < len)//超出字符串长度计算下一层
            {
                ret += s[index]; // 当前行的第一个字母
                add = step - add;// 第一次间距是step -2*i，第二次是2*i,
                index += (i == 0 || i == numRows-1) ? step : add; // 0行和最后一行使用step间距，其余使用add间距
            }
        }
        return ret;
    }
    
    
//    作者：bian-bian-xiong
//    链接：https://leetcode-cn.com/problems/zigzag-conversion/solution/6-z-zi-xing-bian-huan-c-c-by-bian-bian-xiong/
//    来源：力扣（LeetCode）
//    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
