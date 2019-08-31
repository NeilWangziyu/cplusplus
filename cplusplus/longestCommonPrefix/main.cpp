//
//  main.cpp
//  longestCommonPrefix
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

//C++实现前缀树，有点难
using namespace std;

class Tire{
public:
    Tire *children[26];
    int size;
    bool isend=false;
    Tire()
    {
        size=0;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        Tire *root=new Tire();
        for(int i=0;i<strs.size();i++)
        {
            Tire *p=root;
            if(strs[i].empty())return ans;
            for(int j=0;j<strs[i].length();j++)
            {
                if(p->children[strs[i][j]-'a']==NULL)
                {
                    p->children[strs[i][j]-'a']=new Tire();
                    p->size++;
                }
                p=p->children[strs[i][j]-'a'];
            }
            p->isend=true;
        }
        Tire *q=root;
        int k=0;
        while(q->size==1&&q->isend==false)
        {
            for(k=0;k<26;k++)
            {
                if(q->children[k])
                {
                    char temp=k+'a';
                    ans+=temp;
                    break;
                }
            }
            q=q->children[k];
        }
        return ans;
    }
};

class Solution2{
public:
    bool check(vector<string>& strs,int k){
        char c = strs[0][k];
        for(int i = 0;i<strs.size();i++){
            if(strs[i][k] != c){
                return false;
            }
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int len = 0;
        int min_len = INT_MAX;
        for(int i = 0;i<strs.size();i++){
            if(strs[i].size() < min_len){
                min_len = strs[i].size();
            }
        }
        for(;len<=min_len;len++){
            if(!check(strs,len)) break;
        }
        if(len == 0) return "";
        else return strs[0].substr(0,len);
    }
};

class Solution3 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int stringnum = strs.size();
        string compre;
        int pos = 0;
        if(stringnum == 0)
            return compre;
        for(int i = 0; i < stringnum; ++i)
        {
            if(strs[i] == "")
                return compre;
        }
        while(true)
        {
            char letter = strs[0][pos];
            int i;
            for(i = 1; i < stringnum; ++i)
            {
                if(strs[i][pos] != letter || pos == strs[i].length())
                    break;
            }
            if(i != stringnum)
                break;
            compre.push_back(letter);
            if(pos < strs[0].length())
                ++pos;
            else
                break;
        }
        
        return compre;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
