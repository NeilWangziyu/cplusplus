//
//  main.cpp
//  hasCycle
//
//  Created by 王子昱 on 2019/9/1.
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
    bool hasCycle(ListNode *head) {
        if(not head)
            return false;
        if(not head->next)
            return false;
        if(head->next == head)
            return true;
        if(head->next->next == head)
            return true;
        
        ListNode * first = head;
        ListNode * second = head->next;
        
        while(second != NULL and second->next != NULL)
        {
            if (second == first)
                return true;
            else
            {
                second = second->next->next;
                first = first->next;
                
            }
        }
        return false;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n\n";
    return 0;
}
