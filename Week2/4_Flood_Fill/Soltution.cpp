/*
 * Created on Tue May 12 2020
 *
 * Title: Leetcode - Flood Fill
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<vector<int>> newimage;
    void dfs(int sr, int sc, int oldColor, int newColor) {
        // boundary conditions
        if(sr < 0 || sc < 0 || sr >= newimage.size() || sc >= newimage[0].size() || newimage[sr][sc] != oldColor) {
            return;
        }
        newimage[sr][sc] = newColor;
        dfs(sr-1, sc, oldColor, newColor); //going top
        dfs(sr+1, sc, oldColor, newColor); //going botton
        dfs(sr, sc-1, oldColor, newColor); //going left
        dfs(sr, sc+1, oldColor, newColor); //going right
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        newimage = image;
        int oldColor = newimage[sr][sc];
        if(oldColor == newColor) {
            return newimage;
        }
        dfs(sr, sc, newimage[sr][sc], newColor);
        return newimage;
    }
};