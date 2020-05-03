#
# Created on Sun May 03 2020
#
# Title: Leetcode - Ransom Note
#
# Author: Vatsal Mistry
# Web: mistryvatsal.github.io
#

from collections import defaultdict

class Solution:
    def canConstruct(self, ransomeNote, magazine):
        mag_map = defaultdict(int)
        for ch in magazine:
            mag_map[ch] += 1
        for ch in ransomeNote:
            if ch not in mag_map:
                return False
            mag_map[ch] -= 1
        # returns true if all the values in the mag_map are >= zero, else returns false
        return all([val>=0 for val in mag_map.values()])
