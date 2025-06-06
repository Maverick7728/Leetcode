// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// this is done using binarytree and not by maps! Showcasing only the rigth side of the tree

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
// Time complexity is O(n) and space complexity is O(h) where h is the height of the tree.



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
vector<int> helper(TreeNode* root,vector<int>& ans, int level) {
        if(root== NULL){
        return ans;
        }

        if(level == ans.size()){
            ans.push_back(root-> val);
        }

        helper(root-> right, ans, level+1);
        helper(root-> left, ans, level+1);
        return ans;
}

        vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int level = 0;
        vector<int> result = helper(root,ans,level);
        return result;
    }
};
