#
# Created on Wed May 06 2020
#
# Title: Leetcode - First Unique Character in a String
#
# Author: Vatsal Mistry
# Web: mistryvatsal.github.io
#

class Solution:
    def firstUniqueChar(self, s):
        store = dict()
        for ch in s:
            if ch not in store:
                store[ch] = 1
            else:
                store[ch] += 1
        
        for i in range(len(s)):
            if store.get(s[i]) == 1: return i
        return -1

