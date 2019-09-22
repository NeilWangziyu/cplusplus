//
//  main.cpp
//  lowestCommonAncestor
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        else
        {
            if (root->val > p->val and root->val > q->val) {
                return lowestCommonAncestor(root->left, p, q);
            }
            else if(root->val < p->val and root->val < q->val)
            {
                return lowestCommonAncestor(root->right, p, q);
            }
            else
                return root;
        }
    }
    

};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
