//
//  main.cpp
//  addTwoNumbers
//
//  Created by 王子昱 on 2019/7/6.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::map;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = NULL;
        ListNode* pt1 = l1;
        ListNode* pt2 = l2;
        ListNode* ret_head = ret;
        int c = 0;
        
        while (pt1 or pt2) {
            int val1 = 0;
            int val2 = 0;
            
            if (pt1)
            {
                val1 = pt1->val;
                pt1 = pt1->next;
            }
            if (pt2)
            {
                val2 = pt2 -> val;
                pt2 = pt2->next;
            }
            
            int sum = val1 + val2 + c;
            ListNode* node = new ListNode(sum%10);
            c = (int)(sum/10);
            cout << sum <<"  "<< c << endl;
            if (ret != NULL)
            {
                ret->next = node;
                ret = ret->next;
            }
            else{
                ret = node;
                ret_head = ret;
            }
        }
        
        if(c > 0)
        {
            ret->next = new ListNode(c);
        }
        
        return ret_head;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode* l1 = new ListNode(8);
    ListNode* l2 = new ListNode(9);
    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    while (res) {
        cout << res->val << endl;
        res = res->next;
    }
    
    return 0;
}
