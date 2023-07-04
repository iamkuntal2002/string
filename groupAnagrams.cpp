#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(string s : strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(s);
        }
        for(auto pr : mp){
            res.push_back(pr.second);
        }
        return res;
    }
};