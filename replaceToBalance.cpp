#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/replace-the-substring-for-balanced-string/
class Solution {
public:
    int balancedString(string s) {
        unordered_map<char,int> mp;
        int count = 0;
        int n = s.size();
        int req = n/4;
        for(auto &ch : s) mp[ch]++;
        for(auto pr : mp){
            if(pr.second>req) count += pr.second-req;

        }
        return count;
    }
};