#
# Created on Fri May 15 2020
#
# Title: Leetcode - Implement Trie(Prefix Tree)
#
# Author: Vatsal Mistry
# Web: mistryvatsal.github.io
#

class Trie:
    def __init__(self,):
        self.is_end_of_string = False
        self.child = [None for _ in range(26)]
    
    def insert(self, word):
        current = self
        for ch in word:
            if(current.child[ord(ch) - ord('a')] is None):
                current.child[ord(ch) - ord('a')] = Trie();
            current = current.child[ord(ch) - ord('a')]
        current.is_end_of_string = True
    
    def search(self, word):
        current = self
        for ch in word:
            current = current.child[ord(ch) - ord('a')]
            if(current is None):
                return False
        if current.is_end_of_string == True: return True
        return False
    
    def startsWith(self, prefix):
        current = self
        for ch in word:
            current = current.child[ord(ch) - ord('a')]
            if(current is None):
                return False
        return True