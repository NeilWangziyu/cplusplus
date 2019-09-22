//
//  main.cpp
//  swapPairs
//
//  Created by 王子昱 on 2019/9/19.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        else{
            int tem = head->val;
            head->val = head->next->val;
            head->next->val = tem;
            head->next->next = swapPairs(head->next->next);
            return head;
        }
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    return 0;
}
