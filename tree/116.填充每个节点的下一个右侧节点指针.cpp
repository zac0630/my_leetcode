/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start

// Definition for a Node.
/*
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
        root->next = NULL;
        traverse(root->left, root->right);
        return root;
    }

    void traverse(Node* left, Node* right){
        if(left == NULL || right == NULL){
            return;
        }
        left->next = right;
        right->next = NULL;
        traverse(left->left, left->right);
        traverse(left->right, right->left);
        traverse(right->left, right->right);
    }
};
// @lc code=end

