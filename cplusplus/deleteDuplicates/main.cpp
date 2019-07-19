//
//  main.cpp
//  deleteDuplicates
//
//  Created by 王子昱 on 2019/7/19.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
        {
            return head;
            
        }
        ListNode* first = head;
        while (first->next != NULL) {
            if (first->val == first->next->val){
                first->next = first->next->next;
            }
            else{
                first = first->next;
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
