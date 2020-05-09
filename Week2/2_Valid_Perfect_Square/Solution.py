#
# Created on Sat May 09 2020
# 
# Title: Leetcode - Valid Perfect Square
#
# Author: Vatsal Mistry
# Web: mistryvatsal.github.io
#

class Solution():
    def isPerfectSquare(self, num):
        i=1
        while i*i <= num:
            if num % i == 0 and num // i == i:
                return True
            i += 1
        return False