#
# Created on Fri May 01 2020
#
# Title: Leetcode - Frist Bad Version
#
# Author: Vatsal Mistry
# Web: mistryvatsal.github.io
#


# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        if n < 2: return n
        start, end = 1, n
        while start <= end:
            mid = start + (end - start) // 2
            if isBadVersion(mid) and not isBadVersion(mid - 1):
                return mid
            elif isBadVersion(mid - 1):
                end = mid - 1
            else:
                start = mid + 1
        return -1
        
        