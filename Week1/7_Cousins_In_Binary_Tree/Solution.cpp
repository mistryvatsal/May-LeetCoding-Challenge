/*
 * Created on Thu May 07 2020
 *
 * Title: Leetcode - Cousins in Binary Tree
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
    public:
    unordered_map<int, pair<int, int>> store;
    void dfs(TreeNode *root, int level, TreeNode *parent) {
        if(root == NULL) {
            return;
        }
        level += 1;
        int parent_val = parent == NULL ? 0 : parent->val;
        pair<int, int> curr = {level, parent_val};
        store[root->val] = curr;
        if(root->left != NULL) {
            dfs(root->left, level, root);
        }
        if(root->right != NULL) {
            dfs(root->right, level, root);
        }
    }

    bool isCousins(TreeNode *root, int x, int y) {
        dfs(root, -1, NULL);
        auto c1 = store[x];
        auto c2 = store[y];
        
        if(c1.first == c2.first and c1.second != c2.second){
            return true;
        }
        return false;
    }
};
