//
//  main.cpp
//  removeNthFromEnd
//
//  Created by 王子昱 on 2019/9/19.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
            return head;
        
        ListNode* first = head;
        ListNode* second = head;
        ListNode* second_pre = head;

        for (int i= 0; i < n; i ++) {
            first = first->next;
        }
        while (first != nullptr) {
            first = first->next;
            second_pre = second;
            second = second->next;
            
        }
        if (second == head) {
            return head->next;
        }
        else if(second->next == nullptr)
        {
            second_pre->next = NULL;
            return head;
        }
        else{
            second->val = second->next->val;
            second->next = second->next->next;
            return head;
        }
        
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
