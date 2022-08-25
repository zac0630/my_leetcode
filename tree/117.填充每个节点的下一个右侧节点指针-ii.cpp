/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
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
// #include "common.h"
//利用层次遍历，可以得到每一层的节点
class Solution {
private:
    queue<Node*> q;
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        q.push(root);
        int len;
        while(!q.empty()){
            len = q.size();
            for(int i = 0; i < len; i++){
                //如果判断是当前层的最后一个节点
                //i == len - 1时，即是最后一个节点
                Node* cur = q.front();
                q.pop();
                if(i == len - 1){
                    cur->next = NULL;
                }
                else{
                    cur->next = q.front();
                }
                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right != NULL)
                    q.push(cur->right);
            }
        }
        return root;
    }
};
// @lc code=end

