/*
 * Created on Sat May 02 2020
 *
 * Title: Leetcode - Jewels And Stones
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution{
    public:
    unordered_set<char> jewels;
    int count=0;
    int numJewelsInStones(string J, string S) {
        if(J.length() || S.length()) return 0;

        for(auto j: J) {
            jewels.insert(j);
        }
        for(auto s: S) {
            if(jewels.find(s) != jewels.end()) count++;
        }
        return count;
    }
};

