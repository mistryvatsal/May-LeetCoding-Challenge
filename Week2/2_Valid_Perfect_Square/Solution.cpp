/*
 * Created on Sat May 09 2020
 *
 * Title: Leetcode - Valid Perfect Square
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

#include <iostream>

using namespace std;

class Solution {
    public:
    bool isPerfectSquare(int num) {
        for(long int i=1; i*i <= num; ++i) {
            if((num % i == 0) && (num / i == i)) {
                return true;
            }
        }
        return false;
    }
};