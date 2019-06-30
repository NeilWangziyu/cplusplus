//
//  main.cpp
//  isBalanced
//
//  Created by 王子昱 on 2019/6/30.
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int res = check(root);
        if (res == -1) return false;
        else return true;
        
    }
    
    int check(TreeNode* r){
        if (r == NULL) return 0;
        
        if (r->left==NULL and r->right==NULL){
            return 1;
        }
        
        int left_num = check(r->left);

        
        int right_num = check(r->right);
        
        
        if (right_num == -1 or left_num == -1) {
            return -1;
        }
        else{
            if (abs(right_num - left_num) > 1) return -1;
            else{
                return 1 + max(right_num, left_num);
            }
        }
        
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    struct TreeNode root(9);
    struct TreeNode l1(3);
    struct TreeNode r1(0);
    struct TreeNode l2(5);
    struct TreeNode r2(7);
    root.left = &l1;
    root.right = &r1;
    root.right->left = &l2;
    root.right->right = &r2;
    
    cout << root.val << " " << root.left->val << " " <<endl;
    Solution s;
    bool re = s.isBalanced(&root);
    cout << re << endl;
    return 0;
}
