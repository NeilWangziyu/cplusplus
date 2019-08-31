//
//  main.cpp
//  maxDepth
//
//  Created by 王子昱 on 2019/8/31.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>

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
    int maxDepth(TreeNode* root) {
        if(not root)
            return 0;
        else{
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            return 1 + max(left, right);
        }
    }
    
    
    int maxDepth2(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto temp = q.front();
                q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            flag++;
        }
        return flag;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
