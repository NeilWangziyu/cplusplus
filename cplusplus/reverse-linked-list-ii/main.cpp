//
//  main.cpp
//  reverse-linked-list-ii
//
//  Created by 王子昱 on 2019/10/16.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode empty(0);
        ListNode* newHead = &empty;
        newHead->next = head;
        
        ListNode* prev = newHead;
        
        for(int i = 1; i < m;  i++)
        {
            prev = prev->next;
        }
        head = prev->next;
        
        for(int j = m; j < n;  j++)
        {
            ListNode* nex = head->next;
            head->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
        }
        return newHead->next;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
