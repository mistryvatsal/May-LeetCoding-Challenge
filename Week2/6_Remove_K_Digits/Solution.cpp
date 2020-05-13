/*
 * Created on Thu May 14 2020
 *
 * Title: Leetcode - Remove K Digits
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

#include <iostream>

using namespace std;

class Solution {
    public:
    string removeKdigits(string num, int k) {
        if (k == num.length()) return "0";

        int idx = 0;

        while (k > 0) {
            idx = (idx > 0) ? (idx - 1) : 0;
            while (idx < num.length() - 1 && num[idx] <= num[idx + 1]) {
                idx++;
            }
            num.erase(num.begin() + idx);
            k--;
        }

        auto non_zero_index = num.find_first_not_of("0");
        num.erase(0, non_zero_index);

        if (num.length() == 0) return "0";
        return num;
    }
};