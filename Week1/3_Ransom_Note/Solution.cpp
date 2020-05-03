/*
 * Created on Sun May 03 2020
 *
 * Title: Leetcode - Ransom Note   
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    bool canConstruct(string ransomNote, string magazine) {
        // taking a map to store the occurence of characters of magazine string by 
        // incrementing the value by 1 if encountered
        unordered_map<char, int> magazine_map;
        for(auto c: magazine) {
            // incrementing the value of character occurrence by 1
            magazine_map[c]++;
        }

        for(auto c: ransomNote) {
            // if the character from ransomNote string is found in the map, then
            // decrement the value by 1
            if(magazine_map.find(c) != magazine_map.end()) {
                magazine_map[c]--;
            }
            // if the character is not found , return false and terminate further checking
            else {
                return false;
            }
        }
        // if all characters are found in the map, then verify the values of each
        // character in the map now, to be >= zero to be true case,
        // if value is < zero, the return false and terminate further checking
        for(auto it=magazine_map.begin(); it!=magazine_map.end(); ++it) {
            if(it->second < 0) {
                return false;
            }
        }
        // if control reaches here, then return true as the values will be
        // either zero(means exact # of characters in both the strings) or 
        // greateer than zero(means # characters in magazine are in surplus)
        return true;
    }
};