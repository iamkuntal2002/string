#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/determine-if-two-strings-are-close/description/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        if(word1 == word2) return true;
        unordered_set<char> st1, st2;       //checking for character present
        vector<int> freq1(26,0), freq2(26,0);       //checking for frequency irrespective of the orders
        for(int i = 0;i<word1.size();i++){
            st1.insert(word1[i]);
            st2.insert(word2[i]);
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        if(st1 == st2 && freq1 == freq2) return true;
        return false;
    }
};