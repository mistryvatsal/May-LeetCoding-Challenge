#
# Created on Sat May 02 2020
#
# Title: Leetcode - Jewels And Stones
#
# Author: Vatsal Mistry
# Web: mistryvatsal.github.io
#

class Solution:
    def numJewelsInStonesS(self, J, S):
        if len(J)==0 or len(S) == 0: return 0
        count=0
        for s in S:
            if s in J:
                count += 1
        return count

