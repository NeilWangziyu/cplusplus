//
//  main.cpp
//  reverseList
//
//  Created by 王子昱 on 2019/7/5.
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* res_head_pt = head;
        ListNode* k = res_head_pt->next;
        head->next = NULL;
        
        while (k != NULL) {

            ListNode* tem = k->next;
            k->next = res_head_pt;
            res_head_pt = k;
            k = tem;
        }
        head = res_head_pt;
        return head;
        
    }
    
    ListNode* reverseList2(ListNode* head){
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *new_head = reverseList2(head->next);
//        head->next始终是最后一个
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    ListNode root(1);
    cout << root.val << endl;
    
    ListNode r1(2);
    ListNode r2(3);
    ListNode r3(5);
    ListNode* r = &root;
    r->next = &r1;
    r1.next = &r2;
    r2.next = &r3;
    
    Solution s;
    
//    while (r != NULL) {
//        cout << r->val << " " << endl;
//        r = r->next;
//    }
    
    
    ListNode* res = s.reverseList(r);
    while (res != NULL) {
        cout << res->val << " " << endl;
        res = res->next;
    }
    
    
    
    
    
    return 0;
}
