/*
 * Created on Wed May 13 2020
 *
 * Title: Leetcode - Single Element in a sorted array
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

// Time complexity : O(logn)
// Space complexity : O(1)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    // binary search implementation
    int search(vector<int> &nums, int low, int high) {
        if(low > high) return -1;
        if(low == high) {
            return nums[low];
        }

        int mid = low + (high - low) / 2;

        if(mid % 2 == 0) {
            if(nums[mid] == nums[mid+1]) {
                return search(nums, mid+2, high);
            }
            else {
                return search(nums, low, mid);
            }
        }
        else {
            if(nums[mid] == nums[mid-1]) {
                return search(nums, mid+1, high);
            }
            else {
                return search(nums, low, mid-1);
            }
        }
    }

    int singleNonDuplicate(vector<int> &nums) {
        return search(nums, 0, nums.size()-1);
    }
};