#
# Created on Fri May 08 2020
#
# Title: Leetcode - Check if it is a Straight Line
#
# Author: Vatsal Mistry
# Web: mistryvatsal.github.io
#

from sys import maxsize # to get INT_MAX to indicate infinity slope

# Time Complexity : O(n)
# Space Complexity : O(1)
# Approach will be to calculate slope for each 2 consecutive points.
# if they are points of same line slope should be same
# using the equation y = mx + c
# calculating the slope m = y2 - y1 / x2 - x1 using two point formula for equation of line in 2D.
class Solution():
    # utility function to calculate slope
    def calc_slope(self, p1, p2):
        # if x2 - x1 is zero, then return slope as infinity or else
		# direct calculation will result into division by zero exception
        if p1[0] == p2[0]: return float(maxsize)
        return float((p2[1] - p1[1]) / (p2[0] - p1[0]))

    def checkStraightLine(self, coordinates):
        # if only 2 pts exists in given input, then obviously a line exists, return true
        if len(coordinates) == 2: return True
        slope = self.calc_slope(coordinates[0], coordinates[1])
        for pt in range(2, len(coordinates)):
            m = self.calc_slope(coordinates[pt], coordinates[pt-1])
            # if different slope is found, line cannot exists, return false
            if m != slope: return False
        return True