#
# Created on Wed May 13 2020
#
# Title: Leetcode - Single Element In A Sorted Array
#
# Author: Vatsal Mistry
# Web: mistryvatsal.github.io
#
# Time Complexity : O(logn)
# Space Complexity : O(1)

class Solution:
    # Binary search approach for better time complexity
    def search(self, nums, low, high):
        if low > high: return -1
        if low == high: return nums[low]

        mid = low + (high - low) // 2

        if mid % 2 == 0:
            if nums[mid] == nums[mid+1]: return self.search(nums, mid+2, high)
            else: return self.search(nums, low, mid)
        else:
            if nums[mid] == nums[mid-1]: return self.search(nums, mid+1, high)
            else: return self.search(nums, low, mid-1)

     def singleNonDuplicate(self, nums):
         return self.search(nums, 0, len(nums)-1)