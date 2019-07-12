//
//  main.cpp
//  lengthOfLongestSubstring
//
//  Created by 王子昱 on 2019/7/6.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <unordered_set>
#include <set>
using namespace std;

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::map;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//        int length = s.size();
        int res = 0;
        int start = 0;
        string str = "";
        
        for (int i = 0 ; i < s.length(); i++)
        {
            if (str.find(s[i])== -1) {
                str = str + s[i];
            }
            else{
                res = res > str.length()? res : str.length();
                i = s.find_first_of(s[i],start);
                start = i + 1;
                str = "";
            }
        }
        res = res>str.length() ? res:str.length();
        return res;
    
    }
    
    int lengthOfLongestSubstring2(string s) {
        //超时
            int len=0;//存放结果
            int start=0;//存放起始查找位置
            string str="";//存放无重复字符子串
            for(int i=0;i<s.length();i++)
            {
                if(str.find(s[i]) == -1)//未找到重复字符，放入str
                    str = str + s[i];
                else //找到重复子串
                {
                    len=len>str.length()?len:str.length();//更改最大字串长度
                    i = s.find_first_of(s[i],start);//从第start位置开始找s[i]
                    start = i + 1;//下一次查找开始的位置
                    str="";//还原str
                }
            }
            len=len>str.length()?len:str.length();
            return len;
        }
    
    int lengthOfLongestSubstring3(string s) {
        int i = 0,j = 0, n = 0, ans= 0;
        set<char> cont;
        n = s.size();
        set<char>::iterator iter;
        //iterator:遍历
        
        while(i< n && j<n){
            if( (iter=cont.find(s[j])) != cont.end() ){
                cont.erase(s[i++]);
            }
            else {
                cont.insert(s[j++]);
                ans = max(ans, j-i);
            }
            
//            for (iter=cont.begin(); iter!=cont.end(); ++iter) {
//                cout << *iter << "xx" <<endl;
//            }
        }
        return ans;
    }
    
    
    int lengthOfLongestSubstring4(string s) {
        int n = s.length();
        map<char, int> Map_tmp;
        map<char, int>::iterator iter;
        int i= 0, ans = 0;
        
        for(int j = 0; j<n; j++){
            if( (iter = Map_tmp.find(s[j])) != Map_tmp.end() ){
                i = max(i, iter->second);
            }
            ans = max(ans, j-i+1);
            Map_tmp[(s[j])] = j+1;
        }
        return ans;
    }
    
    int lengthOfLongestSubstring5(string s) {
        int i=0,j,k;
        int result = 0;
        //双指针
        for (j = 0; j < s.size(); j++)
        {
            for (k= i; k<j; k++)
            {
                if (s[k] == s[j])
                {
                    i = k + 1;
                    break;
                }
                
            }
            if ((j - i + 1)>result)
                result = j - i + 1;
        }
        return result;
    }
};

    

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    
    cout << "size of set" << s.size() << endl;
    cout << "set maxsize " << s.max_size() << endl;
    //返回set容器可能包含的元素最大个数
    
    cout << "set first item" << *s.begin()<<endl;
    cout << "Set last item" << *s.end()<< endl;
    
    s.clear();
    if (s.empty()) {
        cout << "set is empty" <<  endl;
        
    }
    cout << s.size() <<  endl;
    
    
    Solution solu;
    int res;
    res = solu.lengthOfLongestSubstring("abcabcbb");
    cout << res << endl;
    int res2;
    res2 = solu.lengthOfLongestSubstring3("abcabcbb");
    cout << res2<< endl;
    
    res = solu.lengthOfLongestSubstring("bbbbbbb");
    cout << res << endl;
    res2 = solu.lengthOfLongestSubstring3("bbbbbbb");
    cout << res2<< endl;
    
    return 0;
}
