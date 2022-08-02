/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// #include "common.h"
class Codec {
private:
    string res;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        res.clear();
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode* root, string &res){
        if(root == NULL){
            res.append("#").append(",");
            return;
        }

        //前序位置
        res.append(to_string(root->val)).append(",");

        traverse(root->left, res);
        traverse(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //删除最后一个字符","
        if(data.length()==1){
            return NULL;
        }
        data.append(data, data.length()-1);
        //根据前序遍历还原二叉树（序列带有空指针信息），使用递归
        return build(data);
    }
    TreeNode* build(string &data){
        if(data.empty())
            return NULL;
        //发现是',' 删除这个元素
        if(data[0] == ',')
            data.erase(data.begin());
        
        //发现是'#' 返回空指针，这条子树遍历就到头了
        if(data[0] == '#'){
            data.erase(data.begin());
            return NULL;
        }

        //构造根节点
        // 数值获取 以及 删掉字符串中的数值
        size_t sz;
        TreeNode *root = new TreeNode(stoi(data, &sz)); //stoi截取数字字符串，将其转为int，同时返回数字字符串后的第一个字符位置
        data.erase(0, sz);
        // TreeNode* root = new TreeNode;
        // root->val = data[0];
        // //把这个元素从序列中删除
        // data.erase(data.begin());
        //递归
        root->left = build(data);
        root->right = build(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

