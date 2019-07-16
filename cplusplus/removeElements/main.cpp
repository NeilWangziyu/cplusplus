//
//  main.cpp
//  removeElements
//
//  Created by 王子昱 on 2019/7/16.
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
    ListNode* removeElements(ListNode* head, int val)
    {
        if( head == NULL )
            return NULL;
        while( head->val == val )
        {
            head = head->next;
            if( head == NULL )
                return NULL;
        }
        ListNode *cur = head->next;
        ListNode *pre = head;
        while( cur )
        {
            if( cur->val == val )
            {
                pre->next = cur->next;
                cur = cur->next;
            }
            else
            {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return head;
    }
};

class SolutionMy {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        
        while(head->val == val)
        {
            head = head->next;
            if (not head)
                return NULL;
        }
        
        ListNode *front = head->next;
        ListNode *pre = head;
        
        while(front)
        {
            if (front->val == val)
            {
                pre->next = front->next;
                front = front->next;
            }
            else
            {
                pre = pre->next;
            front = front->next;
            }
        }
        return head;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
