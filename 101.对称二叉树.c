/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool compare(struct TreeNode* p, struct TreeNode* q);
bool isSymmetric(struct TreeNode* root){
        if ( root == NULL) {
                return true;
        }

        return compare(root->left, root->right);
}

bool compare(struct TreeNode* p, struct TreeNode* q) {

        if ((p==NULL) && (q==NULL)){
                return true;
        } else if ((p==NULL) || (q==NULL)) {
                return false;
        }

        if ( p->val != q->val ) {
                return false;
        }
        return compare(p->left, q->right) && compare(p->right, q->left);
}
// @lc code=end

