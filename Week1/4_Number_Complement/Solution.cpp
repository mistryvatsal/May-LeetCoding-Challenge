/*
 * Created on Mon May 04 2020
 *
 * Title: Leetcode - Number Complement
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

// Approach is to use XOR with 1 to flip the bits 
// 0 xor 1 -> 1 {Bit got flipped}
// 1 xor 1 -> 0 {Bit got flipped}

#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int power=1;
        int _num=0;
        while(num > 0) {
            _num = _num + ((num % 2) ^ 1) * power;
            power = power << 1;
            // To prevent leading zeroes
            num = num >> 1;
        }
        return _num;
    }
};

int main() {
    Solution obj;
    cout << obj.findComplement(5);
}