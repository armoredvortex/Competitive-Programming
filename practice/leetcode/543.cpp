/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct wt {
  int height;
  int max_path;
};

wt dim(TreeNode *root) {
  if (root == nullptr) {
    return {0, 0};
  }

  wt lf = dim(root->left);
  wt rt = dim(root->right);

  return {1 + max(lf.height, rt.height),
          max(max(lf.max_path, rt.max_path), lf.height + rt.height)};
}

class Solution {
public:
  int diameterOfBinaryTree(TreeNode *root) { return dim(root).max_path; }
};
