#
# Created on Wed May 06 2020
#
# Title: Leetcode - Majority Element
#
# Author: Vatsal Mistry
# Web: mistryvatsal.github.io
#

# Problem solution using hashmap.
# Time complexity : O(n)
# Space complexity : O(n)
class Solution:
    def majorityElement(self, nums):
        store = dict()
        for i in nums:
            if i not in store:
                store[i] = 1
            else:
                store[i] += 1
        n_by_2 = len(nums) // 2
        result = 0
        for key, val in store.items():
            if val > n_by_2:
                result = key
        return result