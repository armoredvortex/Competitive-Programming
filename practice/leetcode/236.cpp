/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* ans = nullptr;

struct found {
    bool p = false;
    bool q = false;
};

found lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == nullptr){
        return {false, false};
    }
    if(root == p){
        if(lca(root->left, p, q).q == true || lca(root->right, p, q).q == true){
            ans = p;
            return {true, true};
        } else {
            return {true, false};
        }
    }
    if(root == q){
        if(lca(root->left, p, q).p == true || lca(root->right, p, q).p == true){
            ans = q;
            return {true, true};
        } else {
            return {false, true};
        }
    }

    found e = lca(root->left, p, q);
    found f = lca(root->right, p, q);

    if(e.p == true && e.q == true){
        return {true, true};
    } else if(f.p == true && f.q == true){
        return {true, true};
    } else if(e.p == true && f.q == true){
        ans = root;
        return {true, true};
    } else if(e.q == true && f.p == true){
        ans = root;
        return {true, true};
    } else if(e.p == true || f.p == true){
        return {true, false};
    } else if(e.q == true || f.q == true){
        return {false, true};
    } else {
        return {false, false};
    }

}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca(root, p, q);
        return ans;
    }
};