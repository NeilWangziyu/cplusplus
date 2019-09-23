//
//  main.cpp
//  palindrome-linked-list
//
//  Created by 王子昱 on 2019/9/23.
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        ListNode* slow = head;
        ListNode* quick = head;
        while (quick!=nullptr and quick->next!=nullptr) {
            quick = quick->next->next;
            slow = slow->next;
        }
        
        slow->next = reverse(slow->next);
        while (slow!= nullptr) {
            if (head->val != slow->val) {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* r)
    {
        if (r == nullptr or r->next == nullptr) {
            return r;
        }
        ListNode* newHead = reverse(r->next);
        r->next->next = r;
        r->next = nullptr;
        return newHead;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
