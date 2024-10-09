// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

// Example 1:
// Input: p = [1,2,3], q = [1,2,3]
// Output: true

// Example 2:
// Input: p = [1,2], q = [1,null,2]
// Output: false

// Example 3:
// Input: p = [1,2,1], q = [1,1,2]
// Output: false

class Solution
{
public:
    void preorder(TreeNode *p, TreeNode *q, bool &flag)
    {
        if (!p && !q)
            return;
        else if (!p && q || !q && p)
        {
            flag = false;
            return;
        }

        if (p->val != q->val)
        {
            flag = false;
            return;
        }
        preorder(p->left, q->left, flag);
        preorder(p->right, q->right, flag);
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool flag = true;
        preorder(p, q, flag);
        if (flag)
            return true;
        return false;
    }
};