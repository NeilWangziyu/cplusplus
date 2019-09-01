//
//  main.cpp
//  isValidBST
//
//  Created by 王子昱 on 2019/9/1.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(not root)
            return true;
        return isVAlidBSTcore(root, LONG_MIN, LONG_MAX);
        
    }
    
    bool isVAlidBSTcore(TreeNode* root, long minv, long maxv)
    {
        //        minv: at leaset larger
        //        maxv: can not larger
        
        if(not root)
            return true;
        if (root->left)
        {
            if (root->left->val >= root->val or root->left->val <= minv)
                return false;
            
        }
        if (root->right)
        {
            if (root->right->val <= root->val or root->right->val >= maxv)
                return false;
        }
        return isVAlidBSTcore(root->left, minv, root->val) and isVAlidBSTcore(root->right, root->val, maxv);
        
    }
    
    void midOrder(TreeNode* root, vector<int>& list)
    {
        if(root)
        {
            midOrder(root->left, list);
            list.push_back(root->val);
            midOrder(root->right,list);
        }
        return;
    }
    
    bool isValidBST2(TreeNode* root)
    {
        //        非递归
        vector<int> list;
        midOrder(root, list);
        for(int i = 1; i < list.size(); ++i)
        {
            if(list[i] <= list[i-1])
                return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
