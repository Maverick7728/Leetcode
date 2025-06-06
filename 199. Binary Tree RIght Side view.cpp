// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.



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
vector<int> BinaryTree(TreeNode* root,vector<int>& ans, int level) {
        if(root== NULL){
        return ans;
        }

        if(level == ans.size()){
            ans.push_back(root-> val);
        }

        BinaryTree(root-> right, ans, level+1);
        BinaryTree(root-> left, ans, level+1);
        return ans;
}

        vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int level = 0;
        vector<int> result = BinaryTree(root,ans,level);
        return result;
    }
};

