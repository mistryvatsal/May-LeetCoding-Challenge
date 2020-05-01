/*
 * Created on Fri May 01 2020
 *
 * Title: Leetcode - First Bad Version
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

#include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n < 2) {
            return n;
        }

        int start_val = 1;
        int end_val = n;

        while(start_val <= end_val) {
            int mid_val = start_val + (end_val - start_val) / 2;
            if(isBadVersion(mid_val) && !isBadVersion(mid_val - 1)) {
                return mid_val;
            }
            else if(isBadVersion(mid_val - 1)) {
                end_val = mid_val - 1;
            }
            else {
                start_val = mid_val +1;
            }
        }

        return -1; // in case if no bad version is found, otherwise compiler will through warning.
    }
};