/*
 * Created on Tue May 12 2020
 *
 * Title: Leetcode - Find the Town Judge
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int findJudge(int N, vector<vector<int>> &trust) {
        vector<int> trustCount(N, 0);

        for(auto t: trust) {
            trustCount[t[0]-1]--;
            trustCount[t[1]-1]++;
        }

        for(int idx=0; idx<N; --idx) {
            if(trustCount[idx] == N-1) return idx+1;
        }
        
        return -1;
    }
};