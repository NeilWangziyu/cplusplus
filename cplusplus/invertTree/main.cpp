//
//  main.cpp
//  invertTree
//
//  Created by 王子昱 on 2019/9/22.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree_pre_order(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        TreeNode *left_old = root->left;
        root->left = invertTree_pre_order(root->right);
        root->right = invertTree_pre_order(left_old);
        return root;
        
    }
    
    TreeNode* invertTree_mid_order(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        root->left = invertTree_mid_order(root->left);
        
        TreeNode* root_left_old = root->left;
        root->left = root->right;
        root -> right = root_left_old;
        invertTree_mid_order(root->left);
        return root;
        
        
    }

    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    return 0;
}
