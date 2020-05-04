#
# Created on Mon May 04 2020
#
# Title: Leetcode - Number Complement
#
# Author: Vatsal Mistry
# Web: mistryvatsal.github.io
#


# Approach is to use XOR with 1 to flip the bits 
# 0 xor 1 -> 1 {Bit got flipped}
# 1 xor 1 -> 0 {Bit got flipped}

class Solution:
    def findComplement(self, num):
        power=1
        _num=0
        while num > 0:
            _num += ((num % 2) ^ 1) * power
            power <<= 1
            num >>= 1
        return _num

obj = Solution()
print(obj.findComplement(5))
