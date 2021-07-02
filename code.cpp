/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode * deleting(TreeNode* root, int target,bool &check)
    {
        if(root!=NULL)
        {
            if(root->left==NULL && root->right==NULL && root->val==target)
            {
                check=true;
                return NULL;
            }
            root->left=deleting(root->left,target,check);
            root->right=deleting(root->right,target,check);
            return root;
        }
        return NULL;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool check;
        m:
        check=false;
        root=deleting(root,target,check);
        if(check==false)
        {
            return root;
        }
        else
        {
            goto m;
        }
        return root;
    }
};
