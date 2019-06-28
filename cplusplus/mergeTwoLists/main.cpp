//
//  main.cpp
//  mergeTwoLists
//
//  Created by 王子昱 on 2019/6/28.
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


struct mystruct{
    mystruct(int a, int b)
    {
        this->a=a;
        this->b=b;
    };
    int a;
    int b;
    int c;
};


struct mystruct2{
    int a;
    int b;
    int c;
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL){
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1;
        ListNode* p2=l2;
        
        ListNode* ans= new ListNode(0);
        ListNode*p=ans;
        while(p1&&p2){
            if(p1->val<p2->val){
                p->next=new ListNode(p1->val);
                p1=p1->next;
            } else{
                p->next=new ListNode(p2->val);
                p2=p2->next;
            }
            p=p->next;
        }
        
        while (p1){
            p->next=new ListNode(p1->val);
            p1=p1->next;
            p=p->next;
        }
        
        while (p2){
            p->next=new ListNode(p2->val);
            p2=p2->next;
            p=p->next;
        }
        
        ListNode * temp =ans;
        ans=ans->next;
        delete temp;
        return ans;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    
    struct ListNode *ll1;
    struct ListNode *ll2;
    

    
    struct mystruct a(1,2);
    
    cout << a.b << " " << a.a << " " << a.c << endl;
    a.c = 7;
    cout << a.b << " " << a.a << " " << a.c << endl;
    
    
    struct mystruct2 b;
    b.a = 9;
    b.b = 7;
    b.c = 11;
    cout << b.b << " " << b.a << " " << b.c << endl;

    
    struct mystruct2 c={.a = 111, .b = 999, .c = 101};
    
    cout << c.b << " " << c.a << " " << c.c << endl;
    
    struct mystruct2 d={a:0, b:1, c:0};
    cout << d.b << " " << d.a << " " << d.c << endl;



    struct ListNode l1(10);
    struct ListNode l2(15);
    struct ListNode l3(7);
    struct ListNode l4(11);
    l1.next = & l2;
    l2.next = & l3;
    l3.next = & l4;
    
    struct ListNode t1(9);
    struct ListNode t2(115);
    struct ListNode t3(17);
    t1.next = & t2;
    t2.next = & t3;
    
    ListNode* res = s.mergeTwoLists(&l1, &t1);
    
    while (res != NULL) {
        cout << res->val << endl;
        res = res->next;
    }
    
    //    attention: 只有结构体能用 .
    //    对于指针，只能用->
    //    采用 new， 只能是指针
    ListNode* tem = new ListNode(10);
    cout << tem->val << endl;

//    ListNode l1 ListNode(10);
//    ListNode l2 ListNode(15, l1);
//    ListNode l3 ListNode(7, l2);
//    ListNode l4 ListNode(11, l3);
//
//    ListNode t1 ListNode(9);
//    ListNode t2 ListNode(11, t1);
//
//    ll1 = & l4;
//    ll2 = & l5;
    
    
    
    
        
    
    return 0;
}
