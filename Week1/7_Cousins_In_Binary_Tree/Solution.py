#
# Created on Fri May 08 2020
#
# Title: Leetcode - Cousins in Binary Tree 
#
# Author: Vatsal Mistry
# Web: mistryvatsal.github.io
#

class TreeNode:
    def __init__(self, val, left, right):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    store = dict()
    def dfs(self, root, level, parent):
        if root is None:
            return False
        level += 1
        parent_val = 0 if parent is None else parent.val
        store[root.val] = [level, parent_val]
        if root.left is not None:
            self.dfs(root.left, level, root)
        if root.right is not None:
            self.dfs(root.right, level, root)

    def isCousin(self, root, x, y):
        dfs(root, -1, None)
        
        if(self.store[x][0] == self.store[y][0] and self.store[x][1] != self.store[y][1]):
            return True
        else:
            return False

