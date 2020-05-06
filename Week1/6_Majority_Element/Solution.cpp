/*
 * Created on Wed May 06 2020
 *
 * Title: Leetcode - Majority Element
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

// Solution using hashmap datastructure, in cpp using unordered_map
// Time complexity : O(n)
// Space complexity : O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    unordered_map<int, int> store;
    int majorityElement(vector<int>& nums) {
        for(auto i: nums) {
            store[i]++;
        }
        
        int n_by_2=nums.size() / 2, result=0;
        for(auto it=store.begin(); it!=store.end(); ++it) {
            if(it->second > n_by_2) {
                result = it->first;
            }
        }
        return result;
    }
};
