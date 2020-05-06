/*
 * Created on Wed May 06 2020
 *
 * Title: Leetcode - First Unique Character in a String
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
    public:
    unordered_map<char, int> store;
    int firstUniqueChar(string s) {
        for(auto ch: s) {
            store[ch]++;
        }
        for(int i=0; i<s.length(); ++i) {
            if(store[s[i]] == 1) return i;
        }
        return -1;
    }
};