/*
 * Created on Fri May 15 2020
 *
 * Title: Leetcode - Implement Trie (Prefix Tree)
 *
 * Author: Vatsal Mistry
 * Web: mistryvatsal.github.io
 */

#include <iostream>

using namespace std;

class Trie {
    // to store the children nodes.
    Trie* child[26];
    // to indicate if its end of string.
    bool is_end_of_string;
    
    public:
    Trie() {
        // initializing each node upon creation with constructor
        is_end_of_string = false;
        for(int i=0; i<26; ++i) {
            child[i] = nullptr;
        }
    }

    // insert method to insert a string.
    void insert(string word) {
        Trie* current = this;
        for(auto ch : word) {
            current = child[ch - 'a'];
            if(!current->child[ch - 'a']) {
                current->child[ch - 'a'] = new Trie;
            }
            current = current->child[ch - 'a'];
        }
        current->is_end_of_string = true;
    }
    // search method to search if string is present or not.
    bool search(string word) {
        Trie* current = this;
        for(auto ch: word) {
            current = current->child[ch - 'a'];
            if(!current) return false;
        }
        if(current->is_end_of_string == true) return true;
        return false;
    }
    // to search if prefix exists
    bool startsWith(string prefix) {
        Trie* current = this;
        for(auto ch : prefix) {
            current = current->child[ch - 'a'];
            if(!current) return false;
        }
        return true;
    }
};
