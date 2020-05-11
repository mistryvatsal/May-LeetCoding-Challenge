#
# Created on Tue May 12 2020
#
# Title: Leetcode - Flood Fill
#
# Author: Vatsal Mistry
# Web: mistryvatsal.github.io
#

class Solution:
    def dfs(self, image, sr, sc, old_color, new_color):
        if sr < 0 or sc < 0 or sr >= len(image) or sc >= len(image[0]) or image[sr][sc] != old_color:
            return 
        image[sr][sc] = new_color
        self.dfs(image, sr-1, sc, old_color, new_color)
        self.dfs(image, sr+1, sc, old_color, new_color)
        self.dfs(image, sr, sc-1, old_color, new_color)
        self.dfs(image, sr, sc+1, old_color, new_color)

    def floodFill(self, image, sr, sc, newColor):
        old_color = image[sr][sc]
        if old_color != newColor:
            return image
        dfs(image, sr, sc, old_color, newColor)
        return image
