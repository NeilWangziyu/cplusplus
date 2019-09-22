//
//  main.cpp
//  rotateRight
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0) {
            return head;
        }
        if(head == nullptr)
            return head;
        int c = 1;
        ListNode* check = head;
        while (check->next != nullptr) {
            c += 1;
            check = check->next;
        }
        int loop = c - k % c;
        ListNode* tail = check;
        check->next = head;
        check = head;
        for (int i=0; i < loop; i++) {
            check = check->next;
            tail = tail->next;
            
        }
        tail->next = nullptr;
        return check;
        

        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
