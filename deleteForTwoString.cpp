#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/delete-operation-for-two-strings/
class Solution {
public:
    int minDistance(string word1, string word2) {
        unordered_map<char,int> mp;
        for(auto ch : word1) mp[ch]++;
        for(auto ch : word2){
            if(mp.find(ch) != mp.end()) mp[ch]--;
            else mp[ch]++;
            if(mp[ch] == 0) mp.erase(ch);
        }
        int count = 0;
        for(auto pr : mp) count += pr.second;
        return count;
    }
};