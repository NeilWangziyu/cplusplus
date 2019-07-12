//
//  main.cpp
//  Traversal
//
//  Created by 王子昱 on 2019/7/12.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        
        postorderTraversal_core(root, &res);
        return res;
        
    }
    void postorderTraversal_core(TreeNode* r, vector<int>* res)
    {
        if (r==NULL)
            return ;
        if (r->left)
            postorderTraversal_core(r->left, res);
        if(r->right)
            postorderTraversal_core(r->right, res);
        res->push_back(r->val);
        
        return;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        
        preorderTraversal_core(root, &res);
        return res;
    }
    
    void preorderTraversal_core(TreeNode* r, vector<int>* res)
    {
        if (r==NULL)
            return ;
        res->push_back(r->val);
        if (r->left)
            preorderTraversal_core(r->left, res);
        if(r->right)
            preorderTraversal_core(r->right, res);
        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if (root == NULL)
            return res;
        
        midorder(root, &res);
        return res;
        
        
    }
    void midorder(TreeNode* root, vector<int>* r)
    {
        if (root==NULL)
            return;
        
        if (root->left != NULL)
            midorder(root->left, r);
        
        r->push_back(root->val);
        
        if(root->right!=NULL)
            midorder(root->right, r);
        return;
        
    }
    
};




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
