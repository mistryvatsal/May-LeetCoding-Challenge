/*
 * Created on Fri May 08 2020
 *
 * Title: Leetcode - Check if it is a Straight Line
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

#include <iostream>
#include <vector>
#include <bits/stdc++.h> // to get INT_MAX to indicate infinity slope

using namespace std;
// Time Complexity : O(n)
// Space Complexity : O(1)
// Approach will be to calculate slope for each 2 consecutive points.
// if they are points of same line slope should be same
// using the equation y = mx + c
// calculating the slope m = y2 - y1 / x2 - x1 using two point formula for equation of line in 2D.
class Solution {
	// utility function to calculate slope 
	float calc_slope(vector<int> &p1, vector<int> &p2) {
		// if x2 - x1 is zero, then return slope as infinity or else
		// direct calculation will result into division by zero exception
		if(p1[0] == p2[0]) {
			return (float)INT_MAX;
		}
		return (float)(p2[1] - p1[1])/(p2[0] - p1[0]);
	}
	bool checkStraightLine(vector<vector<int>> &coordinates) {
		// if only 2 points exists in given input, then obviously it is a straight line
		if(coordinates.size() == 2) return true;
		float slope = calc_slope(coordinates[1], coordinates[0]);
		for(int i=2; i<coordinates.size(); ++i) {
			float m = calc_slope(coordinates[i-1], coordinates[i]);
			// if a different slope is found, return false 
			if(m != slope) {return false;}
		}
		// return true if all slopes are same and loop is completed 
		return true;
	}
};
