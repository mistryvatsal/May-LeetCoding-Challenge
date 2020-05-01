/*
 * Created on Fri May 01 2020
 *
 * Title: Leetcode - First Bad Version
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

 /**
 * Definition for isBadVersion()
 * 
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        if(n < 2) {
            return n;
        }
        let start = 1;
        let end = n;
        while( start <= end ) {
            let mid = Math.trunc((start + end) / 2);
            if(isBadVersion(mid) && !isBadVersion(mid - 1)) {
                return mid;
            }
            else if(isBadVersion(mid - 1)) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return -1;
    };
};