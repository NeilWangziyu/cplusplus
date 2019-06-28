//
//  main.cpp
//  deleteNode
//
//  Created by 王子昱 on 2019/6/28.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node->next == NULL){
            node = NULL;
            return;
        }
        else{
            int tem = node->next->val;
            node->next = node ->next ->next;
            node->val = tem;
            return;
        }
    }
    
    void deleteNode2(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
